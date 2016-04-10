#include <stdio.h>
#include "gettimeofday.h"
#include <cilk/cilk.h>
#include <time.h>
void srand( unsigned seed ); 



#define N 102400


void quickSort(long int arr[], int left, int right);

int main ()
{ 
	long int number[N];
	int count;
	double start, stop;
	srand( time(NULL) );
	
	for (count=0 ; count<N ; count++ )
	{
		number[count] = rand() % 100 + 1;
	   // printf ("%d, ", number[count]);
	}
	start = wcgettimeofday();	
	quickSort(number, 0, N-4);
	stop = wcgettimeofday();
	printf("\n") ;
	
	for (count=0 ; count<N ; count++)
	{
		 //printf ("%d, ", number[count]);
	}
	
	printf("time = %g\n", stop-start);
	
}

void quickSort(long int arr[], int left, int right) {
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
      };
 
      /* recursion  */

	  if (left < j)
           cilk_spawn quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
		cilk_sync;
		//*/
}
