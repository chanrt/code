#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int max(int arr[], int n) 
{ 
    int mx = arr[0]; 
    for (int i = 1; i < n; i++) 
        if (arr[i] > mx) 
            mx = arr[i]; 
    return mx; 
} 
  
void countSort(int arr[], int n, int exp) 
{ 
    int output[n]; 
    int i, count[10] = {0}; 
  
    for (i = 0; i < n; i++) 
        count[ (arr[i]/exp)%10 ]++; 
  
    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
  
    for (i = n - 1; i >= 0; i--) 
    { 
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
        count[ (arr[i]/exp)%10 ]--; 
    } 
  
    for (i = 0; i < n; i++) 
        arr[i] = output[i]; 
} 

float meanOf(float *time_array)
{
   float sum = 0.0;
   for(int i = 0; i < 10; i++)
   {
      sum = sum + time_array[i];
   }
   return (sum/10.0);
}
  
void radixSort(int arr[], int n) 
{ 
    int m = max(arr, n); 

    for (int exp = 1; m/exp > 0; exp *= 10) 
        countSort(arr, n, exp); 
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
            radixSort(array, n);
            clock_t diff = clock() - start;
            msec = (diff*1000)/CLOCKS_PER_SEC;

            free(array);
            time_array[ll] = msec/1000.0;
        }
        for(int j = 0; j <= 9; printf("%.4f ",time_array[j]), j++);
        //printf("\tMean: %.4f",meanOf(time_array));
        printf("\n");
    }
}