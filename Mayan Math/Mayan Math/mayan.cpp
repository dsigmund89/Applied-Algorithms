// mayan.cpp
// David Sigmund
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int glyphToDigit(string glyph)
{
	if(glyph == "@")
		return 0; 
	else
		return glyph.size();
}

vector<int> base10To20(int s)
{
	vector<int> mayanNums;
	int digit = 0;
	int num = s;

	while(num > 0)
	{
		digit = num % 20;
		num = num / 20;
		mayanNums.push_back(digit);
	}

	return mayanNums;
}

void main () {
	ifstream fin ("mayan.in");
	if (fin) {
		ofstream fout ("mayan.out");
	
	int s;
	int curNum = 0;
	int num1 = -1;
	int num2 = -1;
	char sign;
	string temp;
	string line;
	string glyph;
	bool read = true;
	
		while(read)
		{
			getline(fin,line);
			if(line != "" && line != "#" && line != "+" && line != "-" && line != "0")
			{
				glyph += line;
			}
			else
			{
				 if(line == "")
				 {
					 s = glyphToDigit(glyph);
					 curNum = (curNum * 20) + s;
					 glyph = "";
				 }
				 else if(line == "#")
				 {
					 s = glyphToDigit(glyph);
					 curNum = (curNum * 20) + s;
					 if(num1 == -1)
					 {
						 num1 = curNum;
						 curNum = 0;
					 }
					 else
					 {
						 num2 = curNum;
						 curNum = 0;
						 int result;
						 if(sign == '+')
							 result = num1 + num2;
						 else
							 result = num1 - num2;
						 cout << result;

						 vector<int> mayanNums = base10To20(result);
						 reverse(mayanNums.begin(), mayanNums.end());
						 int index = 0;
						 bool resultEqualsZero = true;
						 for(vector<int>::const_iterator i = mayanNums.begin(); i != mayanNums.end(); ++i)
						 {
							 cout << *i << endl;

							 int asterisk = 0;
							 int linesOfDashes = 0;

							 asterisk = *i%5;
							 linesOfDashes = *i/5;

							 if(asterisk == 0 && linesOfDashes == 0)
								fout << "@" << endl;
							 for(int j = 0; j < asterisk; j++)
							 	fout << "*";
							 if(asterisk != 0)
						 		fout << endl;
					  		 for(int j = 0; j < linesOfDashes; j++)
								fout << "-----" << endl;
							 if(index == mayanNums.size()-1)
								fout << "#" << endl;
							 else
								fout << endl;
							 index++;
							 resultEqualsZero = false;
						 }
						 if(resultEqualsZero)
							 fout << "@" << endl << "#" << endl;

						 num1 = -1;
						 num2 = -1;
					 }
					 glyph = "";
				 }
				 else if(line == "+")
				 {
					 sign = '+';
				 }
				 else if(line == "-")
				 {
					 sign = '-';
				 }
				 else if(line == "0")
				 {
					 read = false;
				 }
			}
			
		}
		fout.close();
		fin.close();
	}
	else {
		cout << "Input file not found." << endl;
	}
}