//
//  main.cpp
//  multiplication table
//
//  Created by Kevin Reinoso on 5/14/16.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    for (int i=1;i<13;i++)
    {
        for(int j=1;j<13;j++)
        {   if(i*j<10)
            {
                std::cout<<' ';
            }
            if(i*j<100)
            {
                std::cout<<' ';
            }
            std::cout<<" "<<i*j<<' ';
        }
        std::cout<< std::endl;
    }
    return 0;
}
