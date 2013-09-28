// barcode.cpp
// David Sigmund
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string interleave(string line)
{
	string interleavedLine;
	
	for(int i = 0; i < line.size(); i+=10)
	{
		string temp1 = line.substr(i,i+5);
		string temp2 = line.substr(i+5,i+9);
		for(int j = 0; j < 5; j++)
		{
			interleavedLine += temp1.at(j);
			interleavedLine += temp2.at(j);
		}
	}
	return interleavedLine;
}

void main () {
	ifstream fin ("barcode.in");
	if (fin) {
		ofstream fout ("barcode.out");

		string line;
	
		getline(fin,line);

		while(fin && line != "0")
		{ 
			if(line.size() % 2 != 0)
			{
				line = "0" + line;
			}

			while(line.find_first_of("0123456789") != string::npos)
			{
				size_t f = line.find("0");
				if(f <= 100)
					if(f % 2 == 0)
						line.replace(f, string("0").length(), "NNWWN");
					else
						line.replace(f, string("0").length(), "nnwwn");
				f = line.find("1");
				if(f <= 100)
					if(f % 2 == 0)
						line.replace(f, string("1").length(), "WNNNW");
					else
						line.replace(f, string("1").length(), "wnnnw");

				f = line.find("2");
				if(f <= 100)
					if(f % 2 == 0)
						line.replace(f, string("2").length(), "NWNNW");
					else
						line.replace(f, string("2").length(), "nwnnw");

				f = line.find("3");
				if(f <= 100)
					if(f % 2 == 0)
						line.replace(f, string("3").length(), "WWNNN");
					else
						line.replace(f, string("3").length(), "wwnnn");

				f = line.find("4");
				if(f <= 100)
					if(f % 2 == 0)
						line.replace(f, string("4").length(), "NNWNW");
					else
						line.replace(f, string("4").length(), "nnwnw");

				f = line.find("5");
				if(f <= 100)
					if(f % 2 == 0)
						line.replace(f, string("5").length(), "WNWNN");
					else
						line.replace(f, string("5").length(), "wnwnn");

				f = line.find("6");
				if(f <= 100)
					if(f % 2 == 0)
						line.replace(f, string("6").length(), "NWWNN");
					else
						line.replace(f, string("6").length(), "nwwnn");

				f = line.find("7");
				if(f <= 100)
					if(f % 2 == 0)
						line.replace(f, string("7").length(), "NNNWW");
					else
						line.replace(f, string("7").length(), "nnnww");

				f = line.find("8");
				if(f <= 100)
					if(f % 2 == 0)
						line.replace(f, string("8").length(), "WNNWN");
					else
						line.replace(f, string("8").length(), "wnnwn");
			
				f = line.find("9");
				if(f <= 100)
					if(f % 2 == 0)
						line.replace(f, string("9").length(), "NWNWN");
					else
						line.replace(f, string("9").length(), "nwnwn");
			}

			fout << "NnNn" << interleave(line) << "WnN" << endl;
			getline(fin,line);
		}
		fout.close();
		fin.close();
	}
	else {
		cout << "Input file not found." << endl;
	}
}