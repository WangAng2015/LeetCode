#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution
{
public:
	string longestCommonPrefix(vector<string> & v_str)
	{
		if (v_str.empty())
			return "";

		for (int i = 0; i < v_str[0].size(); i++)
		{
			for (int j = 0; j < v_str.size(); j++)
			{
				if (v_str[j][i] != v_str[0][i])
				{
					if (i > 0)
						return v_str[0].substr(0, i);
					else
						return "";
				}
			}
		}
		return v_str[0];
	}
};
