#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
	string intToRoman(int num)
	{
		const int indexNum[] = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
		const string indexRom[] = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };
		string roman;
		for (int i = 0; i < 13; i++)
		{
			while (num >= indexNum[i])
			{
				num -= indexNum[i];
				roman += indexRom[i];
			}
		}
		return roman;
	}
};
