#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
	int TASKS;

	scanf("%d", &TASKS);

	while (TASKS != 0)
	{
		int N, P, W, H;
		int p1, q1;
		vector<int> a;
		int total_h = 0;
		int max_size = 0;

		scanf("%d %d %d %d", &N, &P, &W, &H);
		for (int i = 0; i < N; ++i)
		{
			int temp;
			scanf("%d", &temp);
			a.push_back(temp);
		}
		int min;
		if (H > W) min = W;
		else
			min = H;

		for (int i = 1; i < min; ++i)
		{
			p1 = H / i;
			q1 = W / i;

			for (int j = 0; j < N; j++)
			{
				total_h += a[j] / q1 + 1;
			}
			if (total_h < p1 * P)
				max_size = i;
			else
				break;
		}
		printf("%d\n", max_size);
		TASKS--;
	}
}