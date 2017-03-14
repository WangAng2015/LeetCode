#include<iostream>
#include<string>

using namespace std;

class Solution
{
public:
	bool isMatch(const string& str1, const string& str2) {
		return(isMatch(str1.c_str(), str2.c_str()));
	}

	bool isMatch(const char* s, const char* p)
	{
		if (*p == '\0')
			return *s == '\0';

		if (*(p+1) != '*')
		{
			if (*s == *p || (*p == '.'&& *s!='/0'))
				return isMatch(s + 1,p + 1);
			else
				return false;
		}
		else
		{
			while (*s == *p && (*p == '.'&& *s != '/0'))
			{
				if (isMatch(s, p + 2))
					return true;
				s++;
			}
			return (isMatch(s, p + 2));
		}
	}
};

int main()
{
	char *s = "abcd";
	char *p = ".*d";
	Solution Sol;
	cout << Sol.isMatch(s, p);
	system("pause");
}