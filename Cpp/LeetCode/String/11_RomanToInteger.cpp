#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
	
	int map(char str)
	{
		switch (str)
		{
		case 'M':return 1000;
		case 'D':return 500;
		case 'C':return 100;
		case 'L':return 50;
		case 'X':return 10;
		case 'V':return 5;
		case 'I':return 1;
		default:0;
		}
	}

	int romanToInt(const string& roman)
	{
		int num = map(roman[0]);
		for (int i = 1; i < roman.length(); i++)
		{
			if (map(roman[i]) > map(roman[i - 1]))
				num = num - map(roman[i - 1]) + map(roman[i]) - map(roman[i - 1]);
			else
				num += map(roman[i]);

		}
		return num;
	}
};