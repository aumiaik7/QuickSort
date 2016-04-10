#include <stdio.h>
#include <iostream>
//#include "gettimeofday.h"
#include <cstdlib>
#include <cilk/cilk.h>
#include <sys/time.h>

using namespace std;
void srand( unsigned seed ); 
void swap (int&, int&);


#define N 10


void quickSort(long int arr[], int left, int right);

int main ()
{ 
	long int number[N];
	int count;
	struct timeval  start, stop;
	//srand( time(NULL) );
	
	for (count=0 ; count<N ; count++ )
	{
		number[count] = rand() % 100 + 1;
	    //printf ("%d, ", number[count]);
	}
	//start = wcgettimeofday();	
	gettimeofday(&start,NULL);
	quickSort(number, 0, N);
	//stop = wcgettimeofday();
	gettimeofday(&stop,NULL);
	printf("\n") ;
	
	for (count=0 ; count<N ; count++)
	{
		 printf ("%d, ", number[count]);
	}

		
	printf("time = %g\n", stop.tv_usec-start.tv_usec);
	
}

void quickSort(long int arr[], int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];
 
      //i = left - 1;
      //j = right + 1;
	/* partition */
      cilk_for (int m = i; m< (left+right)/2; m++) {
           
	if(arr[m]>pivot )
	{
		while(arr[j]>pivot)
			j--;
		swap(arr[m],arr[j]);
	}
//while (arr[i] < pivot)
           //       i++;
           // while(arr[j] > pivot)
            //      j--;
            //for (int k = 0; arr[i]<pivot; k++)
	   //	i++;
           
	    //for(int l = 0;arr[j]>pivot;l--)
	//	j--;	
            /*if (m <= j) {
                  tmp = arr[m];
                  arr[m] = arr[j];
                  arr[j] = tmp;
                  //i++;
                  j--;
            }*/

	//if(arr[m]<pivot)
		
		
      }
 
      /* recursion  */

	  if (left < j)
          {
	        //cilk_spawn 
		quickSort(arr, left, j);
	  }	
      if (i < right)
            quickSort(arr, i, right);
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
