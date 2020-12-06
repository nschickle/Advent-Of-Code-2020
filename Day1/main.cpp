#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    vector<int> v;
    ifstream inputFile ("input.txt");
    string line;
    int num1;
    int num2;

    if (inputFile.is_open())
    {
        cout << "Part 1: " << "\n";
        while ( getline (inputFile,line) )
        {
            v.push_back(stoi(line));
        }
        vector<int>::iterator it = v.begin();
        vector<int>::iterator it2;
        
        while (it != v.end())
        {
            num1 = *it;
            num1 = 2020 - num1;
            it2 = find(v.begin(), v.end(), num1);
            if(it2 != v.end())
            {
                cout << *it << " " << *it2 << " " << *it * *it2 << "\n";
            }
            it++;   
        }
        cout << "Part 2: " << "\n";
        it = v.begin();
        it2 = v.begin();
        vector<int>::iterator it3;
        while(it != v.end())
        {
            num1 = 2020 - *it;
            num2 = 2020;
            while(it2 != v.end() && num2 != 0)
            {
                num2 = num1 - *it2;
                //cout << num2 << "\n";
                it3 = find(v.begin(), v.end(), num2);
                if(it3 != v.end())
                {
                    cout << *it << " " << *it2 << " " << *it3 << " " << *it * *it2 * *it3 << "\n";
                }
                it2++;
            }
            it2 = v.begin();
            it++;
        }

    }

    inputFile.close();
}