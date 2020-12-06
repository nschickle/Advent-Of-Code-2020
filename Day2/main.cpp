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
    int counter2 = 0;
    int counter3 = 0;
    char c;
    int posChar = 0;
    int posChar2 = 0;
    int count = 0;

    if (inputFile.is_open())
    {
        int pwNum = 0;
        while (!inputFile.eof())
        {
            pwNum++;
            inputFile >> minChar;
            inputFile >> c;
            inputFile >> maxChar;
            inputFile >> passChar;
            inputFile >> c;
            inputFile >> pw;
            //cout << minChar << " " << maxChar << " " << passChar << " " << pw << endl;
            posChar = minChar;
            posChar2 = maxChar;
            
            
            for(string::iterator it=pw.begin();it!=pw.end(); ++it)
            {
                counter2++;
                if(*it == passChar)
                {
                    currChar++;
                    if(counter2 == posChar)
                        count++;
                    if(counter2 == posChar2)
                        count++;
                }
            }
            
            cout << pwNum << ": " << count << "\n";
            if(count == 1)
            {
                counter3++;
            }
            if(currChar >= minChar && currChar <= maxChar)
            {
                //cout << "Pass" << endl;
                counter++;
            }
            
            
            counter2 = 0;
            count = 0;
            currChar = 0;          
        }
        cout << "Part 1: " << counter << " Valid Passwords\n";
        cout << "Part 2: " << counter3 << " Valid Passwords\n";

    }

    inputFile.close();

    return 0;
}