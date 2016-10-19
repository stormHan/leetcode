#include "main.h"

bool isValid(string s)
{
	stack<int> stk;

	for (int i = 0; i < s.size(); ++i)
	{
		switch ((s[i]))
		{
		case '(': stk.push(1); break;
		case ')': if (stk.size() == 0) return false; if (stk.top() != 1) return false; stk.pop(); break;
		case '[': stk.push(2); break;
		case ']': if (stk.size() == 0) return false; if (stk.top() != 2) return false; stk.pop(); break;
		case '{': stk.push(3); break;
		case '}': if (stk.size() == 0) return false; if (stk.top() != 3) return false; stk.pop(); break;
		}
	}
	if (stk.size() != 0) return false;
	return true;
}