#include <vector>

using namespace std;

class MinStack
{
public:
	int minimum = 0x7fffffff;
	vector<int> index;
	vector<int> stack;

	int head = -1;

	void push(int x)
	{
		head++;
		if (x <= minimum)
		{
			index.push_back(head);
			minimum = x;
		}
		stack.push_back(x);
	}

	void pop()
	{
		int a = this->top();
		if (a == minimum)
		{
			index.pop_back();
			minimum = stack[index[index.size() - 1]];
		}
		head--;
		stack.pop_back();
	}

	int top()
	{
		return stack[stack.size() - 1];
	}

	int getMin(){
		return stack[index[index.size() - 1]];
	}

};