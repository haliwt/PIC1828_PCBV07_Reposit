#include "ShellSort.h"


/********************************************************************************
  *
  *Function Active: Shell sort
  *
  *
  *
********************************************************************************/
void ShellSort(int *arr, int size)
{
    int i, j, tmp, increment;
    for (increment = size/ 2; increment > 0; increment = increment / 2)
    {
        for (i = increment; i < size; i++) 
			{
	            tmp = arr[i];
	            for (j = i - increment; j >= 0 && tmp < arr[j]; j=j -increment) 
				{
	                arr[j + increment] = arr[j];
                }
            arr[j + increment] = tmp;
        }
   }
}
/*********************************************
 * 
 * look for maximum value
 * 
 *********************************************/

uint Maximum_Value(int arr[], uchar n)
{
    int i;
    uint  max = 0; // the maximum
    uint  great= 0;  // the second maximum
    for(int i = 0; i<n; i++)
    {
	 /*??arr[i]???? ??????arr[i]??max???????max ?
	    ?max????mid??????arr[i]??max  ??max???mid?*/
	if(arr[i]>max)
        {
	        great = max;
	        max = arr[i];
	}
        else if(arr[i]>great)
        {
            /*  ????? arr[i]??????*/
	    	great = arr[i];//  ??arr[i]??mid
	}

    }
    return max ;
}

/*********************************************
 *
 * look for mimiumum value
 *
 *********************************************/
uint Minimum_Value(int arr[], uchar N)
{
    int i;
    uint min = 255; // the maximum
    uint colmin= 254;  // the second maximum
    for(int i = 0; i<N; i++)
    {
	    /*??arr[i]???? ??????arr[i]??max???????max ?
		?max????mid??????arr[i]??max  ??max???mid?*/
	if(arr[i] < min)
        {
	        colmin = min;
	        min = arr[i];
	}
        else if(arr[i] < colmin)
        {
            /*  ????? arr[i]??????*/
	    	colmin= arr[i];//  ??arr[i]??mid
	}

    }
    return min ;
}