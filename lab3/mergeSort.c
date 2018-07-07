#include "mySort.h"
#include "metrics.h"
void merge(int array[],unsigned int first,unsigned int mid,unsigned int last)
{
  /*In the lab manual this line was given.*/
  int temp[MAX_SIZE_N_TO_SORT];
 
  /*Here is where I define what I will be using in my code*/
  int i;
  int fir1 = first;
  int fir2 = first;
  int middle=mid+1;
  
   while((fir1<=mid)&&(middle<=last))
   {    
     
     if(myCompare(array[fir1],array[middle])<=0)
     {
       
       myCopy(&array[fir1],&temp[fir2]);
       fir1++;
      }
else
    {
    myCopy(&array[middle],&temp[fir2]);
    middle++;
    }
   fir2++;
    }
  
  if(myCompare(fir1,mid)>0)
   {
     for(i=middle;i<=last;i++)
     {
     myCopy(&array[i],&temp[fir2]);
     fir2++;
     }
   }
else
    {
   for(i=fir1;i<=middle;i++){
     myCopy(&array[i],&temp[fir2]);
     fir2++;
     }
    }
   
  for(i=first;i<=last;i++){
   myCopy(&temp[i],&array[i]);
  }
}
void mySort(int array[], unsigned int first, unsigned int last)
    {
     int mid;
      if (first < last) 
      {
         mid = ((first + last) / 2);
         mySort(array, first, mid);
         mySort(array, mid+1, last);
         merge(array, first, mid, last);
    }
}
