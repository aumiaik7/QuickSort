#include <stdio.h>
#include <sys/time.h>
//void srand( unsigned seed ); 

#define N 60000

void quickSort(int arr[], int left, int right);

int main ()
{ 
	int number[N];
	int count;
	struct timeval  start, stop;
	srand( time(NULL) );
	
	for (count=0 ; count<N ; count++ )
	{
		number[count] = rand() % 100 + 1;
	   // printf ("%d, ", number[count]);
	}
	//start = wcgettimeofday();	
	gettimeofday(&start,NULL);
	quickSort(number, 0, N-1);
	gettimeofday(&stop,NULL);
	//stop = wcgettimeofday();
	printf("\n") ;
	
	for (count=0 ; count<N ; count++)
	{
		 printf ("%d, ", number[count]);
	}
	

	double time = (stop.tv_sec+(double)stop.tv_usec/1000000) - (start.tv_sec+(double)start.tv_usec/1000000)	;	
	//printf("time = %g\n", 
	cout<<endl<<"Sorting done in "<<time<< " seconds"<<endl;
	
}

void quickSort(int arr[], int left, int right) {
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
           quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
		
}
