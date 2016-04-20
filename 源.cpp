#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

//#define ONE		0x0100100
//#define TWO		0x1011101
//#define THREE	0x1101101
//#define FOUR    0x0101110
//#define FIVE	0x1101011
//#define SIX		0x1111011
//#define SEVEN	0x0100101
//#define EIGHT	0x1111111
//#define NINE	0x1101111
//#define ZERO	0x1110111\


int K, N, S;
int ans = 0;
bool led[5][10]; //代表K个数字中，每个能拼成的哪些数字， 0 代表不能拼成，1代表能拼成
bool old[10][9] = {
	{ 0, 1, 1, 1, 1, 1, 1, 1 },
	{ 0, 0, 0, 1, 0, 0, 1, 0 },
	{ 0, 1, 0, 1, 1, 1, 0, 1 },
	{ 0, 1, 1, 1, 1, 0, 1, 1 },
	{ 0, 0, 1, 1, 1, 0, 1, 0 },

	{ 0, 1, 1, 0, 1, 0, 1, 1 },
	{ 0, 1, 1, 0, 1, 1, 1, 1 },
	{ 0, 1, 0, 1, 0, 0, 1, 0 },
	{ 0, 1, 1, 1, 1, 1, 1, 1 },
	{ 0, 1, 1, 1, 1, 0, 1, 1 }
};

void dfs(int step, int value)
{
	if (step == K)
	{
		if (value < N) ans++;
	}
	else
	{
		for (int i = 0; i < 10; ++i)
		{
			if (led[step][i])
			{
				value *= 10;
				value += i;

				dfs(step + 1, value);
			}
		}
	}
}

int main()
{
	cin >> S;
	while (S--)
	{
		cin >> K >> N;
		for (int i = 0; i < K; ++i)
		{
			string s;
			getline(cin, s);
			istringstream str(s);
			int c;
			while (str >> c)
			{
				for (int j = 0; j < 10; ++j)
				{
					if (old[j][c] && led[i][j])
					{
						led[i][j] = true;
					}
					else
					{
						led[i][j] = false;
					}
				}
			}
		}
		dfs(0, 0);
		cout << ans << endl;
	}

	return 0;
}