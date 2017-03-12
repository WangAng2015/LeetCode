#include<iostream>
#include<string>
#include <vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	string preProcess(const string& str)//�׼�^ β��$ �����#
	{
		if (str.empty())
			return "^$";

		string s = "^";
		for (int i = 0; i < str.length(); i++)
		{
			s += "#";
			s += str[i];
		}
		s += "#$";
		return s;
	}

	string longestPalindrome(const string & str)
	{
		string s = preProcess(str);
		int id = 0;
		int r = 0;
		const int n = s.length();
		vector<int> P(n, 0);
		for (int i = 1; i < n-1; i++)//��β����Ҫ
		{
			int j = id - (i - id);//�ԳƵ�

			P[i] = (r > i) ? min(P[j], r - i) : 0;//�㷨����

			while (s[i + P[i] + 1] == s[i - P[i] - 1])//��������
				P[i]++;

			if (P[i] + i > r)
			{
				r = P[i] + i;
				id = i;
			}
		}

		//��������P[i],����������Ӵ�
		int maxP = 0;
		int idP = 0;
		for (int i = 1; i < n - 1; i++) {
			if (P[i] > maxP) {
				maxP = P[i];
				idP = i;
			}
		}
		return str.substr((idP - maxP - 1) / 2, maxP);

	}

};

int main()
{
	string str = "12asddsa56";
	Solution sol;
	cout << sol.longestPalindrome(str) << endl;

	system("pause");
}