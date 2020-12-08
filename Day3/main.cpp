#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

vector<vector<char>> traverse(vector<vector<char>> v1, int f, int g);
void outputNewPath(vector<vector<char>> v1);

int main()
{
    ifstream input ("input.txt");
    string currLine;
    
    char currChar;

    vector<vector<char>> v1;
    vector<vector<char>> vCopy = v1;
    

    if(input.is_open())
    {
        while (!input.eof())
        {   
            
            vector<char> v2;
            input >> currLine;
            for(string::iterator it = currLine.begin(); it != currLine.end();it++)
            {
                v2.push_back(*it);
            } 
            v1.push_back(v2);
        }
        //vCopy = traverse(v1,1,1);
        //outputNewPath(vCopy);
        vCopy = traverse(v1,3,1);
        outputNewPath(vCopy);
        //vCopy = traverse(v1,5,1);
        //outputNewPath(vCopy);
        //vCopy = traverse(v1,7,1);
        //outputNewPath(vCopy);
        //vCopy = traverse(v1,3,2);
        //outputNewPath(vCopy);
        
    }
    else
    {
        input.close();
    }
    
    return 0;
}

vector<vector<char>> traverse(vector<vector<char>> v1,int f, int g)
{
    int counter = 0;
    int xpos = 0;
    int ypos = 0;
    for (int i = 0, j = 0; j < v1.size();i = i + f, j + g)
    {
        
        //cout << ypos << endl;
        if(ypos >= 31)
        {
            ypos = ypos - 31;
        }
        if (v1[xpos][ypos] == '#')
        {
            v1[xpos][ypos] = 'X';
            counter++;
        }
        else
        {
            v1[xpos][ypos] = 'O';
        }
        
        xpos = xpos + g;
        ypos = ypos + f;

        }
        
        cout << counter << endl;
        return v1;
}

void outputNewPath(vector<vector<char>> v1)
{
    for (int i = 0; i < v1.size(); i++) 
    { 
        for (int j = 0; j < v1[i].size(); j++)
        {
            cout << v1[i][j]; 
        }
        cout << endl; 
    }
}
