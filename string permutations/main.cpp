//
//  main.cpp
//  string permutations
//
//  Created by Kevin Reinoso on 5/11/16.

#include <algorithm>
#include <iostream>
#include<cstring>
#include <fstream>
void swap(char& , char& );
void permutation(std::string ,int ,int,int& );
int factorial(int);
using namespace std;
int main(int argc, char *argv[]) {
    //ifstream stream(argv[1]); //if
    string line="hata";
    //while (getline(stream, line))
    {
        int x=0;
        permutation(line, 0, int(line.length() - 1),x);
        cout << endl;

    }
        return 0;
}


void permutation(string s,int i,int n,int& x)
{
    int j;


    if (i == n)
    {
        fprintf(stdout,s.c_str());
        x++;
        if ( x< factorial (int (s.length()) ))
            fprintf(stdout,"\,");
    
    }
    else
    {
        for (j = i; j < s.length(); j++)
        {
            
            swap(s[i],s[j]);
            permutation(s, i + 1, n, x);
            swap(s[i],s[j]);
        }
    }
   


}

void swap(char& a, char& b)
{
    char temp;
    temp = a;
    a = b;
    b = temp;
}
            
int factorial(int x)
{
    int y=1;
    for (int i=2;i<=x;i++)
    {
        y*=i;
    }
    return y;
}
