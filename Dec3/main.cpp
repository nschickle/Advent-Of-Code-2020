#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <istream>
#include <cctype>

using namespace std;

int main()
{
    ifstream inputFile ("input.txt");
    ofstream outputFile ("output.txt");
    string currLine;
    string pw;
    int minChar = 0;
    int maxChar = 0;
    char passChar;
    int counter = 0;
    int currChar = 0;
    char c;

    if (inputFile.is_open())
    {
        while (!inputFile.eof())
        {
            inputFile >> minChar;
            inputFile >> c;
            inputFile >> maxChar;
            inputFile >> passChar;
            inputFile >> c;
            inputFile >> pw;
            cout << minChar << " " << maxChar << " " << passChar << " " << pw << endl;

            for(string::iterator it=pw.begin();it!=pw.end(); ++it)
            {
                if(*it == passChar)
                {

                    currChar++;
                    
                }
            }

            if(currChar >= minChar && currChar <= maxChar)
            {
                cout << "Pass" << endl;
                counter++;
            }
            currChar = 0;          
        }
        cout << counter;
    }

    inputFile.close();

    return 0;
}