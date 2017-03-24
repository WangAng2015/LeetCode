#include<iostream>
#include<string>

using namespace std;

class Solution
{
public:
	string findNext(const string& str)
	{
		int j = 0;
		string nextStr;
		while (j < str.length())
		{
			int m = 1;//ÀÛ¼ÆÊýÄ¿
			int k = j + 1;
			while (k < str.length() && str[k] == str[j])
			{
				m++;
				k++;
			}
			nextStr += (m + '0');
			nextStr += str[j];
			j += m;
		}
		return nextStr;
	}

	string countAndSay(const int n)
	{
		if (n <= 1)
			return "1";

		string str = "1";
		for (int i = 1; i < n; i++)
		{
			str = findNext(str);
		}
		return str;


	}
};

int main()
{
	Solution Sol;
	cout << Sol.countAndSay(3) << endl;
	system("pause");
	return 0;
}