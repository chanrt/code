#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int *bubbleSort(int *array, int n)
{
    int tmp;
    for(int i = (n-1); i >= 0; i--)
    {
        for(int j = 0; j < i; j++)
        {
            if(array[j] > array[j+1])
            {
                tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }
        }
    }

    return array;
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
            array = bubbleSort(array, n);
            clock_t diff = clock() - start;
            msec = (diff*1000)/CLOCKS_PER_SEC;

            free(array);
            time_array[ll] = msec/1000.0;
        }
        for(int j = 0; j <= 9; printf("%.4f ",time_array[j]), j++);
        printf("\n");
    }
}