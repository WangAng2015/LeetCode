#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	int myAtoi(const string& str)
	{
		if (str.empty())
			return 0;
		int i = str.find_first_not_of(' ');
		int sign = 1;
		if (str[i] == '+')
			i++;
		else if (str[i] == '-')
		{
			sign = -1;
			i++;
		}
		string snum;
		for (size_t j = i; j < str.length(); j++)
		{
			if (isdigit(str[j]))
				snum += str[j];
			else
				break;
		}
		int len = snum.length();
		long long num = 0;
		if (len > 0)
		{
			for (size_t k = 0; k < snum.length(); k++)
			{
				num = num * 10 + snum[k] - '0';
				if (num > INT_MAX)
					return sign ? INT_MAX : INT_MIN;
			}
			return sign*int(num);
		}
		return 0;
	}
};

int main()
{
	Solution sol;
	string str1 = " -2147483648";
	cout << sol.myAtoi(str1) << endl;

	system("pause");
}