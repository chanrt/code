#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int *insertionSort(int *array, int n)
{
    int tmp, q;

    for(int p = 1; p < n; p++)
    {
        tmp = array[p];

        for(q = p; q > 0 && tmp < array[q-1]; q--)
            array[q] = array[q-1];
        array[q] = tmp;
    }

    return array;
}

int main()
{
    int n;
    float msec = 0.0;
    
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
            array = insertionSort(array, n);
            clock_t diff = clock() - start;
            msec = (diff*1000) / CLOCKS_PER_SEC;
            free(array);

            time_array[ll] = msec/1000.0;
        }
        for(int j = 0; j <= 9; printf("%.3f ",time_array[j]), j++);
        printf("\n");
    }
}