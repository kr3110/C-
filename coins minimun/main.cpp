//
//  main.cpp
//  coins minimun (5,3 and 1)  
//
//  Created by Kevin Reinoso on 5/10/16.
//


 #include <iostream>
 #include<cstring>
 #include <fstream>
 using namespace std;
 int main(int argc, char *argv[]) {
 //ifstream stream(argv[1]);
 string line;
 //while (getline(stream, line))
 {
     cin>>line;
     char cstr[line.length()];
     strcpy(cstr, line.c_str());
     int x=atoi(cstr);
     int sum=0;
     while(x>0)
     {
         if(x/5>0)
         {
             sum+=x/5;
             x=x%5;
        }
         else if(x/3>0)
         {
             sum+=x/3;
             x=x%3;
         }
         else
         {
            sum+=x;
            x-=x;
         }
}
     
     cout<<sum;
 }
 
 return 0;
 }
