/*---------------leetcode-----------------
------------Dynamic Programming-----------
----------------storm Han-----------------
----------------2016.03.01----------------

Question describing:
	Say you have an array for which the ith element is the price of a given stock on day i.
	If you were only permitted to complete at most one transaction
	(ie, buy one and sell one share of the stock), 
	design an algorithm to find the maximum profit.

*/

#include <vector>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {

		if (prices.size() < 2)
			return 0;
		int maxPro = 0;
		int currentMin = prices[0];

		for (int i = 0; i < prices.size(); i++)
		{
			if (prices[i] < currentMin)
				currentMin = prices[i];
			if (prices[i] - currentMin > maxPro)
				maxPro = prices[i] - currentMin;
		}
		return maxPro;
	}
		int maxProfit2(vector<int>& prices){

			if (prices.size() < 2)
				return 0;

			int maxPro = 0;
			int currentMin = prices[0];

			for (int i = 0; i < prices.size(); i++)
			{
				if (prices[i] < currentMin)
					currentMin = prices[i];
				if (prices[i] - currentMin > maxPro)
					maxPro = prices[i] - currentMin;
			}
			return maxPro;
		}
};