/*---------------leetcode-----------------
----------------Rotate Image--------------
----------------storm Han-----------------
----------------2016.04.28----------------

Question describing:

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells 
are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
['A','B','C','E'],
['S','F','C','S'],
['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/
#include <vector>
#include <string>
#include <stack>
using namespace std;

//DFS 很容易超时超时超时
bool flag = false;

vector<vector<bool>> visited;

void dfs(int step, int n, vector<vector<char>>& board, string word, int i, int j)
{
	if (flag == true) return;
	if (step == n)
	{
		flag = true;
		return;
	}
	else
	{
		vector<vector<bool>> store = visited;
		int m = board.size() - 1;
		int k = board[0].size() - 1;

		if (i > 0)
		{
			if (board[i - 1][j] == word[step + 1] && visited[i - 1][j] == false)
			{
				visited = store;
				visited[i - 1][j] = true;
				dfs(step + 1, n, board, word, i - 1, j);
			}
		}
		if (j > 0)
		{
			if (board[i][j - 1] == word[step + 1] && visited[i][j - 1] == false)
			{
				visited = store;
				visited[i][j - 1] == true;
				dfs(step + 1, n, board, word, i, j - 1);
			}
		}
		if (i < m)
		{
			if (board[i + 1][j] == word[step + 1] && visited[i + 1][j] == false)
			{
				visited = store;
				visited[i + 1][j] = true;
				dfs(step + 1, n, board, word, i + 1, j);
			}
		}
		if (j < k)
		{
			if (board[i][j + 1] == word[step + 1] && visited[i][j + 1] == false)
			{
				visited = store;
				visited[i][j + 1] = true;
				dfs(step + 1, n, board, word, i, j + 1);
			}
		}
	}
}


bool exist(vector<vector<char>>& board, string word) {
	if (word.size() == 0) return false;

	for (int i = 0; i < board.size(); ++i)
	{
		vector<bool> b;
		for (int j = 0; j < board[0].size(); ++j)
		{
			b.push_back(false);
		}
		visited.push_back(b);
	}

	vector<vector<bool>> store = visited;
	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board[0].size(); ++j)
		{
			if (board[i][j] == word[0])
			{
				visited = store;
				visited[i][j] = true;
				dfs(0, word.size() - 1, board, word, i, j);
			}

		}
	}

	return flag;

}

//用栈来解决问题，我还不太熟
struct Node
{
	char c;
	int x;
	int y;
	int p;    //next trial is 0-up, 1-down, 2-left, 3-right
	Node(char newc, int newx, int newy, int newp) : c(newc), x(newx), y(newy), p(newp) {}
};

class Solution {
public:



	bool exist(vector<vector<char>>& board, string word) {
		if (board.empty() || board[0].empty())
			return false;
		int m = board.size();
		int n = board[0].size();

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] == word[0])
				{// maybe a success
					stack<Node> stk;
					Node curnode(word[0], i, j, 0);
					stk.push(curnode);
					board[curnode.x][curnode.y] = '*';
					int wind = 1;
					if (wind == word.size())
						return true;
					while (!stk.empty())
					{
						if (stk.top().p == 0)
						{
							stk.top().p = 1;
							if (stk.top().x > 0 && board[stk.top().x - 1][stk.top().y] == word[wind])
							{
								Node nextnode(word[wind], stk.top().x - 1, stk.top().y, 0);
								stk.push(nextnode);
								board[nextnode.x][nextnode.y] = '*';
								wind++;
								if (wind == word.size())
									return true;
								continue;
							}
						}
						if (stk.top().p == 1)
						{
							stk.top().p = 2;
							if (stk.top().x < m - 1 && board[stk.top().x + 1][stk.top().y] == word[wind])
							{
								Node nextnode(word[wind], stk.top().x + 1, stk.top().y, 0);
								stk.push(nextnode);
								board[nextnode.x][nextnode.y] = '*';
								wind++;
								if (wind == word.size())
									return true;
								continue;
							}
						}
						if (stk.top().p == 2)
						{
							stk.top().p = 3;
							if (stk.top().y > 0 && board[stk.top().x][stk.top().y - 1] == word[wind])
							{
								Node nextnode(word[wind], stk.top().x, stk.top().y - 1, 0);
								stk.push(nextnode);
								board[nextnode.x][nextnode.y] = '*';
								wind++;
								if (wind == word.size())
									return true;
								continue;
							}
						}
						if (stk.top().p == 3)
						{
							stk.top().p = 4;
							if (stk.top().y < n - 1 && board[stk.top().x][stk.top().y + 1] == word[wind])
							{
								Node nextnode(word[wind], stk.top().x, stk.top().y + 1, 0);
								stk.push(nextnode);
								board[nextnode.x][nextnode.y] = '*';
								wind++;
								if (wind == word.size())
									return true;
								continue;
							}
						}
						//restore
						board[stk.top().x][stk.top().y] = stk.top().c;
						stk.pop();
						wind--;
					}
				}
			}
		}
		return false;

	}
};