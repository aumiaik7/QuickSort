#include<iostream>
#include<cstdlib>

using namespace std;
int PARTITION(int [],int ,int );
void QUICKSORT(int [],int ,int );
int PIVOT(int [],int,int );

int main()
{
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter the elements in the array"<<endl;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    cout<<"sorting using Quick sort"<<endl;
    int p=1,r=n;

    QUICKSORT(a,p,r);

   cout<<"sorted form"<<endl;
   for(int i=1;i<=n;i++)
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
         QUICKSORT(a,p,q-1);
         QUICKSORT(a,q+1,r);
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
