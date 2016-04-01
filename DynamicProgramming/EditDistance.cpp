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

//����һ����̬�滮����Ŀ
//���Ⱦ�����ʾ���õ����ĵ��ƹ�ʽ
//	d[i][j]��val��ʾ		word1��ǰi����ĸ---->word2��ǰj����ĸ   ��������ٲ��衣
//	��һ���۲죬���word1[i]��word2[j]��ͬ����d[i+1][j+1] = d[i][j]
//	������ǣ�����Ҫ���У���ӣ��滻����ɾ���� d[i+1][j+1] = min{ d[i+1][j]+1, d[i][j+1]+1, d[i][j]+1 }
#include <string>

using namespace std;
