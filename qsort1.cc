#include <stdio.h>
#include <iostream>
//#include "gettimeofday.h"
#include <cstdlib>
#include <cilk/cilk.h>
#include <sys/time.h>
#include <vector>
#include <algorithm>

using namespace std;
void srand( unsigned seed ); 
void swap (int&, int&);


#define N 100


void quickSort(vector<int>&, int left, int right);

int main ()
{ 
	vector<int> number;
	//long int number[N];
	int count;
	struct timeval  start, stop;
	//srand( time(NULL) );
	
	number.reserve(N);
	for (count=0 ; count<N ; count++ )
	{
		number.push_back(rand() % 100 + 1);
	    //printf ("%d, ", number[count]);
	}
	//start = wcgettimeofday();	
	gettimeofday(&start,NULL);
	quickSort(number, 0, N-1);
	//stop = wcgettimeofday();
	gettimeofday(&stop,NULL);
	printf("\n") ;
	
	for (count=0 ; count<N ; count++)
	{
		 printf ("%d, ", number.at(count));
	}

		
	printf("time = %g\n", stop.tv_usec-start.tv_usec);
	
}

void quickSort(vector<int>& arr, int left, int right) {
      //if(left>right)
    	//  return;
		int i = left, j = right;
      int tmp;
      int pivot = arr.at((left + right) / 2);
      vector<int> leftVec;
      vector<int> rightVec;
      vector<int> midVec;
    		  //arr[(left + right) / 2];
 

      //i = left - 1;
      //j = right + 1;
	/* partition */
    for (int i = left; i<= right; i++) {
    	if(arr.at(i) < pivot)
    		leftVec.push_back(arr.at(i));
    	else if(arr.at(i) > pivot)
    		rightVec.push_back(arr.at(i));
    	else
    		midVec.push_back(arr.at(i));
      }
      //rightVec.push_back(pivot);
    //leftVec.push_back(pivot);
    vector<int> set1(leftVec.size()+midVec.size());
    //set1.reserve(leftVec.size()+midVec.size());
    set_union( leftVec.begin(), leftVec.end(),midVec.begin(), midVec.end(), set1.begin() );
    set_union( set1.begin(), set1.end(),rightVec.begin(), rightVec.end(), arr.begin()+left );
      /* recursion  */

	  if (leftVec.size() > 1)
          {
	        //cilk_spawn 
		quickSort(arr, left, leftVec.size()+left - 1);
	  }	
      //if ((right - rightVec.size()-1) <right)
	  if (rightVec.size() > 1)
            quickSort(arr, (left+leftVec.size()+midVec.size()) , right);
		//cilk_sync;
		//*/
}

void swap(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
