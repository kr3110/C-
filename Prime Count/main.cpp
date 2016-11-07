
//
//  main.cpp
//  prime count
//
//  Created by Kevin Reinoso on 5/11/16.

#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;
int counT(int,int);
int main(int argc, const char * argv[])
{
    //ifstream stream(argv[1]);
    string line;
    //while(getline(stream,line))
    {
        cin>>line;
        int numb[2];
        char cstr[line.length()];
        strcpy(cstr, line.c_str());
        char* token=strtok(cstr,",");
        int i=0;
        while(token)
        {
            numb[i]=atoi(token);
            token = strtok(NULL, ",");
            i++;
        }
        cout<<counT(numb[0],numb[1])<<endl;
    }
    return 0;
}


int counT(int x,int y)
{
    int j,i,count=0;
    bool flag;
    for(i=x;i<=y;i++)
    {
        flag=0;
        for(j=2;j<=i/2;j++)
        {
            if(!(i%j))
            {
                flag=true;
                break;
            }
        }
        if(!flag)
            count++;
        
    }
   
    return count;
}
