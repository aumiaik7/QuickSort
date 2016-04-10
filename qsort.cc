#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<sys/time.h>
#include<cilk/cilk.h>
using namespace std;

#define SIZE 1000

int PARTITION(int [],int ,int );
void QUICKSORT(int [],int ,int );
int PIVOT(int [],int,int );

int main()
{
    struct timeval start,stop;
    int n;
    //cout<<"Enter the size of the array"<<endl;
    //cin>>n;
    int a[SIZE];
    //cout<<"Enter the elements in the array"<<endl;
    for(int i=1;i<=SIZE;i++)

    {
        //cin>>a[i];
        a[i] = rand() % 100 + 1;
    }

    cout<<"sorting using Quick sort"<<endl;
    int p=1,r=SIZE;

    gettimeofday(&start,NULL);	
    QUICKSORT(a,p,r);
    gettimeofday(&stop,NULL);

   cout<<"Total time:"<<stop.tv_usec - start.tv_usec<<endl;
   cout<<"sorted form"<<endl;
   for(int i=1;i<=30;i++)
   {
       cout<<"a["<<i<<"]="<<a[i]<<endl;
   }
     return 0;
}

void QUICKSORT(int a[],int p,int r)
    {
        int q;
        if(p<r)
        {
         q=PIVOT(a,p,r);
//         cilk_spawn 
	 QUICKSORT(a,p,q-1);
         QUICKSORT(a,q+1,r);
	 //cilk_sync;
        }
    }

 int PIVOT(int a[],int p,int r)
 {
        int i=p+rand()%(r-p+1);
        int temp;
        temp=a[r];
        a[r]=a[i];
        a[i]=temp;
        return PARTITION(a,p,r);
  }

 int PARTITION(int a[],int p,int r)
 {
        int temp,temp1;
        int x=a[r];
        int i=p-1;
        for(int j=p;j<=r-1;j++)
        {
            if(a[j]<=x)
            {

                i=i+1;
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
        temp1=a[i+1];
        a[i+1]=a[r];
        a[r]=temp1;
        return i+1;
  }
