<<<<<<< HEAD
/*---------------leetcode-----------------
---------------Level : Easy---------------
------------------is Ugly-----------------
----------------storm Han-----------------
----------------2016.03.19----------------

Question describing:
Easy, no need to concentrate on

*/
bool isUgly(int num) {
	if (num <= 0) return false;
	if (num == 1) return true;

	while (num != 1)
	{
		if (num % 2 == 0)
		{
			num = num / 2;
		}
		else if (num % 3 == 0)
		{
			num = num / 3;
		}
		else if (num % 5 == 0)
		{
			num = num / 5;
		}
		else
		{
			return false;
		}
	}

	return true;
=======
/*---------------leetcode-----------------
---------------Level : Easy---------------
------------------is Ugly-----------------
----------------storm Han-----------------
----------------2016.03.19----------------

Question describing:
Easy, no need to concentrate on

*/
bool isUgly(int num) {
	if (num <= 0) return false;
	if (num == 1) return true;

	while (num != 1)
	{
		if (num % 2 == 0)
		{
			num = num / 2;
		}
		else if (num % 3 == 0)
		{
			num = num / 3;
		}
		else if (num % 5 == 0)
		{
			num = num / 5;
		}
		else
		{
			return false;
		}
	}

	return true;
>>>>>>> 62ecb277e79aab08296e767ad6966f02a9fcf0f1
}