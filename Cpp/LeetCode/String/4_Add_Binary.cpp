#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string addBinary(const string& str1, const string& str2)
	{
		string a = str1;
		string b = str2;
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		size_t n = a.length() > b.length() ? a.length() : b.length();
		int carry = 0;
		string s;
		for (size_t i = 0; i < n; i++)
		{
			int an = i < a.length() ? a[i] - '0' : 0;
			int bn = i < b.length() ? b[i] - '0' : 0;
			int temp = an + bn + carry;
			carry = 0;
			if (temp > 1)
			{
				carry = 1;
				temp -= 2;
			}
			s.insert(s.begin(), temp + '0');
		}
		if (carry == 1)
			s.insert(s.begin(), '1');
		return s;

	}
};

int main()
{
	Solution sol;
	cout << sol.addBinary("1010", "1011") << endl;

	system("pause");
}