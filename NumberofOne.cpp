/*---------------leetcode-----------------
------------Dynamic Programming-----------
----------------storm Han-----------------
----------------2016.04.09----------------

Question describing:
Write a function that takes an unsigned integer and returns the number of ¡¯1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ¡¯11' has binary representation 00000000000000000000000000001011, so the function should return 3.

*/

int hammingWeight(uint32_t n) {
	int count = 0;
	while (n != 0)
	{
		int a = n % 2;
		if (a == 1) count++;

		n /= 2;
	}
	return count;
}