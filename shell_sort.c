#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void shellSort(int *array, int n) 
{ 
    for (int gap = n/2; gap > 0; gap /= 2) 
    { 
        for (int i = gap; i < n; i++) 
        {  
            int temp = array[i], j;           
            for (j = i; j >= gap && array[j - gap] > temp; j = j - gap) 
                array[j] = array[j - gap]; 
            array[j] = temp; 
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
            shellSort(array, n);
            clock_t diff = clock() - start;
            msec = (diff*1000)/CLOCKS_PER_SEC;

            free(array);
            time_array[ll] = msec/1000.0;
        }
        for(int j = 0; j <= 9; printf("%.4f ",time_array[j]), j++);
        printf("\n");
    }
}