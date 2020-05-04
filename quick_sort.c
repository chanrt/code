#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int medianThree(int *array, int left, int right, int center)
{
    if(array[left] <= array[center] && array[center] <= array[right]) return center;
    else if(array[left] <= array[right] && array[right] <= array[center]) return right;
    else return left;
}

void quicksort(int *array, int left, int right){
   int i, j, pivot , temp;
   if(left < right){
      pivot = medianThree(array, left, right, (right - left) / 2);

      temp = array[left];
      array[left] = array[pivot];
      array[pivot] = temp;

      i = left;
      j = right;

      while(i < j)
      {
         while(array[i] <= array[pivot] && i < right)
            i++;
         while(array[j] > array[pivot])
            j--;
         if(i < j)
         {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
         }
      }

      temp = array[pivot];
      array[pivot] = array[j];
      array[j] = temp;

      quicksort(array, left, j-1);
      quicksort(array, j+1, right);
   }
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
            quicksort(array, 0, n-1);
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