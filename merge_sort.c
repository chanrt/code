#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int array[], int left, int middle, int right) 
{ 
    int i, j, k; 
    int n1 = middle - left + 1; 
    int n2 =  right - middle; 
  
    int *left_subarray = (int *) malloc(n1*sizeof(int));
    int *right_subarray = (int *) malloc(n2*sizeof(int));
  
    for (i = 0; i < n1; i++) 
        left_subarray[i] = array[left + i]; 
    for (j = 0; j < n2; j++) 
        right_subarray[j] = array[middle + 1+ j]; 
  

    i = 0;  
    j = 0; 
    k = left; 
    while (i < n1 && j < n2) 
    { 
        if (left_subarray[i] <= right_subarray[j]) 
        { 
            array[k] = left_subarray[i]; 
            i++; 
        } 
        else
        { 
            array[k] = right_subarray[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) 
    { 
        array[k] = left_subarray[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) 
    { 
        array[k] = right_subarray[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int *array, int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(array, l, m); 
        mergeSort(array, m+1, r); 
  
        merge(array, l, m, r); 
    } 
} 

void main()
{
    int n, ll;
    float msec;

    for(n = 10000; n <= 100000; n += 10000)
    {
        float time_array[10];
        for(ll = 0; ll <= 9; ll++)
        {
            int *array = (int *) malloc(n*sizeof(int));

            srand(time(NULL));
            for(int i = 0; i < n; i++)
            {
                array[i] = (rand() % n);
            }

            clock_t start = clock();
            mergeSort(array, 0, n-1);
            clock_t diff = clock() - start;
            msec = (diff*1000)/CLOCKS_PER_SEC;
            free(array);

            time_array[ll] = msec/1000.0;
        }
        for(int j = 0; j <= 9; printf("%.4f ",time_array[j]), j++);
        printf("\n");
    }
}