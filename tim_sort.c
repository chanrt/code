#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define RUN 32

int min(int a, int b)
{
    if(a > b) return b;
    else return a;
}

void insertionSort(int *array, int left, int right) 
{ 
    for (int i = left + 1; i <= right; i++) 
    { 
        int temp = array[i]; 
        int j = i - 1; 
        while (array[j] > temp && j >= left) 
        { 
            array[j+1] = array[j]; 
            j--; 
        } 
        array[j+1] = temp; 
    } 
} 

void merge(int *array, int left, int middle, int right) 
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

void timSort(int *array, int n) 
{ 
    for (int i = 0; i < n; i+=RUN) insertionSort(array, i, min((i+31), (n-1)));

    for (int size = RUN; size < n; size = 2*size) 
    { 
        for (int left = 0; left < n; left += 2*size) 
        { 
            int mid = left + size - 1; 
            int right = min((left + 2*size - 1), (n-1)); 
 
            merge(array, left, mid, right); 
        } 
    } 
} 

int main()
{
    int n;
    float msec;

    for(int n = 10000; n <= 100000; n += 10000)
    {
        float time_array[10];
        for(int ll = 0; ll <= 9; ll++)
        {
            int *array = (int *) malloc(n*sizeof(int));

            srand(time(NULL));
            for(int i = 0; i < n; i++)
            {
                array[i] = (rand() % n);
            }
            clock_t start = clock();
            timSort(array, n);
            clock_t diff = clock() - start;
            msec = (diff*1000)/CLOCKS_PER_SEC;

            free(array);
            time_array[ll] = msec/1000.0;
        }
        for(int j = 0; j <= 9; printf("%.4f ",time_array[j]), j++);
        printf("\n");
    }
}