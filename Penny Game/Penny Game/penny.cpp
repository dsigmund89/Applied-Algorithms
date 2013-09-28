// Penny.cpp
// David Sigmund
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

void main () {

	string line;
	int n = 0;
	int TTT = 0;
	int TTH = 0;
	int THT = 0;
	int THH = 0;
	int HTT = 0;
	int HTH = 0;
	int HHT = 0;
	int HHH = 0;
	string tosses[40];
	int tossesInt[40];
	int index = 0;

	ifstream fin ("penny.in");
	if (fin) {
		ofstream fout ("penny.out");

		getline(fin,line);
		n = atoi(line.c_str());

		while(n != 0)
		{
			getline(fin,line);
			tosses[index] = line;

			for(int i = 0; i < 40; i++)
			{
				tossesInt[i] = tosses[index].at(i);
			}
			for(int i = 0; i < 38; i++)
			{
				if(tossesInt[i] == 84 && tossesInt[i+1] == 84 && tossesInt[i+2] == 84)
				{ TTT++; }
				else if(tossesInt[i] == 84 && tossesInt[i+1] == 84 && tossesInt[i+2] == 72)
				{ TTH++; }
				else if(tossesInt[i] == 84 && tossesInt[i+1] == 72 && tossesInt[i+2] == 84)
				{ THT++; }
				else if(tossesInt[i] == 84 && tossesInt[i+1] == 72 && tossesInt[i+2] == 72)
				{ THH++; }
				else if(tossesInt[i] == 72 && tossesInt[i+1] == 84 && tossesInt[i+2] == 84)
				{ HTT++; }
				else if(tossesInt[i] == 72 && tossesInt[i+1] == 84 && tossesInt[i+2] == 72)
				{ HTH++; }
				else if(tossesInt[i] == 72 && tossesInt[i+1] == 72 && tossesInt[i+2] == 84)
				{ HHT++; }
				else
				{ HHH++; }
			}
			n--;

			fout << TTT << " " << TTH << " " << THT << " " << THH << " " << HTT << " " << HTH << " " << HHT << " " << HHH;
			
			if(n != 0)
			{
				fout << endl;
			}
			TTT = 0;
			TTH = 0;
			THT = 0;
			THH = 0;
			HTT = 0;
			HTH = 0;
			HHT = 0;
			HHH = 0;
		}
		fout.close();
		fin.close();
	}
	else {
		cout << "Input file not found." << endl;
	}
	cout << "Complete" << endl;
	system("Pause");
}