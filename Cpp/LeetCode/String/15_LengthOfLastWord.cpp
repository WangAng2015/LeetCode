#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

//class solution {
//public:
//	int lengthoflastword(const string& str)
//	{
//		if (str.empty())
//			return 0;
//
//		string s = str;
//		while (s[s.length() - 1] == ' ')
//			s.pop_back();
//		if (s.empty())
//			return 0;
//
//		int i = s.find_last_of(' ');
//		return (s.length() -1 - i);
//	}
//};

//class Solution
//{
//public:
//	int lengthOfLastWord(const string& str)
//	{
//		if (str.empty())
//			return 0;
//		int indexEnd = str.length() - 1;
//		while (str[indexEnd] == ' ')
//			indexEnd--;
//		int len = 0;
//		while (indexEnd >= 0 && str[indexEnd] != ' ')
//		{
//			len++;
//			indexEnd--;
//		}
//		return len;
//	}
//};

class Solution
{
public:
	int lengthOfLastWord(const string& s)
	{
		auto first = find_if(s.rbegin(), s.rend(), ::isalpha);
		auto last = find_if_not(first, s.rend(), ::isalpha);
		return distance(first, last);
	}
};


int main()
{
	Solution Sol;
	cout << Sol.lengthOfLastWord("ab cd  ") << endl;
	system("pause");
	return 0;
}