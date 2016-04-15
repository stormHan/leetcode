/*---------------leetcode-----------------
---------------Level : Easy---------------
---------------Bulls and Cows-------------
----------------storm Han-----------------
----------------2016.04.15----------------

Question describing:

You are playing the following Bulls and Cows game with your friend: 
You write down a number and ask your friend to guess what the number is. 
Each time your friend makes a guess, you provide a hint that indicates 
how many digits in said guess match your secret number exactly in both 
digit and position (called "bulls") and how many digits match the secret 
number but locate in the wrong position (called "cows"). Your friend will
use successive guesses and hints to eventually derive the secret number.

For example:

Secret number:  "1807"
Friend's guess: "7810"
Hint: 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)
Write a function to return a hint according to the secret number and friend's guess, 
use A to indicate the bulls and B to indicate the cows. In the above example, your 
function should return "1A3B".

Please note that both secret number and friend's guess may contain duplicate digits, for example:

Secret number:  "1123"
Friend's guess: "0111"
In this case, the 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow, and 
your function should return "1A1B".

*/
#include <vector>
#include <string>
#include <map>

using namespace std;

string getHint(string secret, string guess) {
	map<char, int> hmap;
	int countA = 0;
	int countB = 0;
	string::iterator it1 = secret.begin();
	string::iterator it2 = guess.begin();

	for (; it1 != secret.end();)
	{
		if (*it1 == *it2)
		{
			countA++;
			it1 = secret.erase(it1);
			it2 = guess.erase(it2);
		}
		else
		{
			if (hmap.count(*it1) == 0)
			{
				hmap.insert(pair<char, int>(*it1, 1));
			}
			else
			{
				hmap[*it1]++;
			}
			it1++; it2++;
		}
	}

	for (it2 = guess.begin(); it2 != guess.end(); ++it2)
	{
		if (hmap.count(*it2) > 0)
		{
			if (hmap[*it2] > 0)
			{
				countB++;
				hmap[*it2]--;
			}

		}
	}

	char t[256];
	string s;

	sprintf(t, "%d", countA);
	s = t;
	sprintf(t, "%d", countB);
	string temp = t;
	s += 'A' + temp + 'B';

	return s;
}
