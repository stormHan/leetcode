/*---------------leetcode-----------------
----------------Level : hard--------------
----------------storm Han-----------------
----------------2016.03.28----------------

Question describing:
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word :

a) Insert a character
b) Delete a character
c) Replace a character
*/

//这是一道动态规划的题目
//首先经过提示，得到它的递推公式
//	d[i][j]的val表示		word1的前i个字母---->word2的前j个字母   所需的最少步骤。
//	进一步观察，如果word1[i]和word2[j]相同，则d[i+1][j+1] = d[i][j]
//	如果不是，则需要进行，添加，替换或者删除。 d[i+1][j+1] = min{ d[i+1][j]+1, d[i][j+1]+1, d[i][j]+1 }
#include <string>

using namespace std;
