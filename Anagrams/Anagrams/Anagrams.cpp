// Anagrams.cpp
// David Sigmund
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

void main () {
    
    string line1, line2;
    int a = 0;
    int b = 0;

    ifstream fin ("anagrams.in");
    if (fin) {
        ofstream fout ("anagrams.out");
        
        getline(fin,line1);
        getline(fin,line2);

        while(fin && (line1 != "<end>" || line2 != "<end>"))
        {
            //changes all characters to lowercase
            transform(line1.begin(), line1.end(), line1.begin(), tolower);
            //sorts the line
            sort(line1.begin(), line1.end());
            //these lines remove punctuation and spaces and digits
            line1.erase(remove_if(line1.begin(), line1.end(), ispunct), line1.end());
            line1.erase(remove_if(line1.begin(), line1.end(), isspace), line1.end());
			line1.erase(remove_if(line1.begin(), line1.end(), isdigit), line1.end());
            //cout<<"1."<<line1<<"\n";

            transform(line2.begin(), line2.end(), line2.begin(), tolower);
            sort(line2.begin(), line2.end());
            line2.erase(remove_if(line2.begin(), line2.end(), ispunct), line2.end());
            line2.erase(remove_if(line2.begin(), line2.end(), isspace), line2.end());
			line2.erase(remove_if(line2.begin(), line2.end(), isdigit), line2.end());

            //cout<<"2."<<line2<<"\n";


            if(line1.compare(line2) == 0)
            {
                fout << "YES" << endl;
            }
            else { fout << "NO" << endl; }

            getline(fin,line1);
            getline(fin,line2);
        }


        fout.close();
        fin.close();
        cout << "Complete!" << endl;
    }
    else {
        cout << "Input file not found." << endl;
    }

	system("Pause");
}