//
//  main.cpp
//  QuickSort
//
//  Created by Kevin Reinoso on 11/6/16.
//  Copyright © 2016 Kevin Reinoso. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>

#define ARRAY_SIZE 100000 // max # of elements in array

using namespace std;

// function prototypes
void quickSort(int[], int, int);
int main() {
    
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
    clock_t begin=clock();
    // sort using radix algorithm, passing max element
    quickSort(nums,0,max);
    
    // print sorted array
    cout << "After:\r\n";
    for (int i=0; i<ARRAY_SIZE; i++)
        cout << "\t" << nums[i] << "\r\n";
    clock_t end=clock();
    double totaltime=((double)end-(double)begin)/CLOCKS_PER_SEC;
    cout<< "time of sorting: "<<totaltime<< " seconds"
    ;
    return 0;
}

void quickSort(int arr[], int left, int right)
{
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];
    
    /* partition */
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    /* recursion */
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}
