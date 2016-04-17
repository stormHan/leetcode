/*
-------------LeetCode-----------------
-------------Storm han----------------
-----------Fisrt Bad Version----------
------------2016.04.17----------------

Decription:
You are a product manager and currently leading a team to develop a new product. 
Unfortunately, the latest version of your product fails the quality check. 
Since each version is developed based on the previous version, all the versions 
after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first
bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version
is bad. Implement a function to find the first bad version. You should minimize 
the number of calls to the API.
*/
bool isBadVersion(int n)
{
	if (n > 11111)
		return true;
	return false;
}

int findBadversion(int left, int right)
{
	if (right - left <= 1)
	{
		if (isBadVersion(left)) return left;
		else    return right;
	}

	int half = left / 2 + right / 2;

	if (isBadVersion(half))
		return findBadversion(left, half);
	else
	{
		return findBadversion(half + 1, right);
	}
}

int firstBadVersion(int n) {
	int ret = findBadversion(0, n);
	return ret;
}