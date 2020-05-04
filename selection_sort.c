#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int *selectionSort(int *array, int n)
{
    int tmp_min, index, tmp;

    for(int i = 0; i < n; i++)
    {
        tmp_min = array[i];
        index = i;
        for(int j = i; j < n; j++)
        {
            if(tmp_min > array[j])
            {
                tmp_min = array[j];
                index = j;
            }
        }
        tmp = array[i];
        array[i] = tmp_min;
        array[index] = tmp;
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

            for(int i = 0; i < n; i++)
            {
                array[i] = (rand() % n);
            }

            clock_t start = clock();
            array = selectionSort(array, n);
            clock_t diff = clock() - start;
            msec = (diff*1000)/CLOCKS_PER_SEC;
            free(array);

            time_array[ll] = msec/1000.0;
        }
        for(int j = 0; j <= 9; printf("%.4f ", time_array[j]), j++);
        printf("\n");
    }
}