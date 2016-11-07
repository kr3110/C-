//
//  main.cpp
//  mergesort
//
//  Created by Kevin Reinoso on 11/6/16.
//  Copyright © 2016 Kevin Reinoso. All rights reserved.
//


#include <iostream> /* cout */
#include <cstdlib> /* srand, rand */
#include <ctime> /* time() */
#include <list> /* list */

#define ARRAY_SIZE 100000 // max # of elements in array

using namespace std;
int  merge  (int list1[ ] , int size1 , int list2[ ] , int size2 , int list3[ ],int size);
void merge_sort (int array[], int size);
int main() {
    int A[ARRAY_SIZE/2];
    int B[ARRAY_SIZE/2];
    int nums[ARRAY_SIZE];
    int i;
    int max=0;
    
    srand(time(0));
    
    // store random numbers to array, print their current order
    cout << "Before:\r\n";
    for (i=0; i<ARRAY_SIZE; i++) {
        // generate random #, 1-1000
        nums[i] = rand()%100000 + 1;
        
        // determine max element upon addition to array
        max = (nums[i] > max)? nums[i]: max;
        cout << "\t" << nums[i] << "\r\n";
    }
    
    cout << endl << endl;
    for(i=0;i<ARRAY_SIZE;i++)
    {
        if(i<ARRAY_SIZE/2)
            A[i]=nums[i];
        else
            B[i]=nums[i];
        
    }
    clock_t begin=clock();
    // sort using radix algorithm, passing max element
    merge_sort(nums,max+1);
    
    // print sorted array
    cout << "After:\r\n";
    for (int i=0; i<ARRAY_SIZE; i++)
        cout << "\t" << nums[i] << "\r\n";
    clock_t end=clock();
    cout<< "time of sorting: "<<end-begin<< " seconds"
    ;
    return 0;
}

void merge_sort (int array[], int size)
{
    int temp[size];
    int mid, i;
    if (size < 2) {
        return;
    }
    else {
        mid = size / 2;
        merge_sort(array, mid);
        merge_sort(array + mid, size - mid);
        merge (array, mid, array + mid, size - mid, temp,size);
        for (i = 0; i < size; i++) {
            array[i] = temp[i];
        }
    }
}

int  merge  ( int list1[ ] , int size1 , int list2[ ] , int size2 , int list3[ ], int size)
{
    int i1, i2, i3;
    if (size1+size2 > size) {
        return false;
    }
    i1 = 0; i2 = 0; i3 = 0;
    /* while both lists are non-empty */
    while (i1 < size1 && i2 < size2) {
        if (list1[i1] < list2[i2]) {
            list3[i3++] = list1[i1++];
        }
        else {
            list3[i3++] = list2[i2++];
        }
    }
    while (i1 < size1) {
        /* copy remainder of list1 */
        list3[i3++] = list1[i1++];
    }
    while (i2 < size2) {
        /* copy remainder of list2 */
        list3[i3++] = list2[i2++];
    }
    return true;
}


