/**
----------------leetcode------------------
----------------storm han-----------------
----------------2016.04.30


Question describing:

Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

Subscribe to see which companies asked this question
*/


int romanToInt(string s) {  
        int ret = toNumber(s[0]);  
        for (int i = 1; i < s.length(); i++) {  
            if (toNumber(s[i - 1]) < toNumber(s[i])) {  
                ret += toNumber(s[i]) - 2 * toNumber(s[i - 1]);  
            } else {  
                ret += toNumber(s[i]);  
            }  
        }  
        return ret;  
    }  
      
    int toNumber(char ch) {  
        switch (ch) {  
            case 'I': return 1;  
            case 'V': return 5;  
            case 'X': return 10;  
            case 'L': return 50;  
            case 'C': return 100;  
            case 'D': return 500;  
            case 'M': return 1000;  
        }  
        return 0;  
    }  