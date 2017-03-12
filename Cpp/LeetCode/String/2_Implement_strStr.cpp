#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	int strStr(const string& str, const string& sub)
	{
		if (sub.empty())
			return 0;
		if (sub.length()>str.length())
			return -1;
		size_t n = str.length() - sub.length() + 1;
		for (size_t i = 0; i < n; i++)
		{
			size_t j = i, k = 0;
			while (j < str.length() && k < sub.length() && str[j] == sub[k])
			{
				j++;
				k++;
			}
			if (k == sub.length())
				return i;
		}
		return -1;
	}
};

int main()
{
	Solution sol;
	string str1 = "abb";
		string str2 = "abaaa";
	cout << sol.strStr(str1, str2) << endl;

	system("pause");
}