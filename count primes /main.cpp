//
//  main.cpp
//  count primes between two numbers
//
//  Created by Kevin Reinoso on 5/2/16.
//

/* Sample code to read in test cases:
 #include <iostream>
 #include <fstream>
 using namespace std;
 int main(int argc, char *argv[]) {
 ifstream stream(argv[1]);
 string line;
 while (getline(stream, line)) {
 // Do something with the line
 }
 return 0;
 } */
#include <iostream>
#include <fstream>
using namespace std;
bool is_prime(int&);
int main(int argc, const char * argv[])
{
    //ifstream stream(argv[1]);
    string line="1, 1000";
    //while(getline(stream,line))
    {
        int numb[2];
        char cstr[line.length()];
        strcpy(cstr, line.c_str());
        char* token=strtok(cstr,",");
        int i=0;
        while(token)
        {
            numb[i]=atoi(token);
            token = strtok(NULL, " ");
            i++;
        }
        int counter=0;
        for(int j=numb[0];j<=numb[1];j++)
        {
            if(is_prime(j))
            {
                counter++;
            }
        }
        cout<<counter<<endl;
    }
    return 0;
}

bool is_prime(int& n )
{
    if (n == 1)
        return false;
    if (n == 2)
        return true;
    if (n == 3)
        return true;
    if (n % 2 == 0)
        return false;
    if (n % 3 == 0)
        return false;
    int i = 5;
    int w = 2;
    while (i * i <= n)
    {
        if (n % i == 0)
            return false;
        i += w;
        w = 6 - w;
    }
    return true;
}
