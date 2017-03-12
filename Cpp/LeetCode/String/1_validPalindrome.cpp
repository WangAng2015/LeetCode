#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	bool isPalindrome(const string & str)
	{
		string s;
		for (size_t i = 0; i < str.length(); i++)
		{
			if (isalnum(str[i]))
				s += tolower(str[i]);
		}
		if (s.empty())
			return true;
		for(size_t j = 0, k = s.length()-1; j < k; j++, k--)
		{
			if (s[j] != s[k])
				return false;
		}
		return true;
	}
};

int main()
{
	string str = "Aa.";
	Solution sol;
	cout << sol.isPalindrome(str) << endl;

	system("pause");
}