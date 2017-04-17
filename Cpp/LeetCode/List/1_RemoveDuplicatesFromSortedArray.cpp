#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

class Solution
{
public:
	int removeDuplicates(vector<int> & vec)
	{
		if (vec.empty())
			return 0;
		int index = 0;
		int len = vec.size();
		for (int i = 1; i < len; i++)
		{
			if (vec[i] != vec[i - 1])
			{
				index++;
				vec[index] = vec[i];
			}
		}
		return index + 1;
	}
};

int main()
{
	vector<int> V{ 1,1,2,3 };
	Solution Sol;
	int n = Sol.removeDuplicates(V);
	for (auto x : V)
		cout << x << endl;
	cout << "length: " << n << endl;
	system("pause");
	return 0;
}
