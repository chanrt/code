#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct MinHeap
{
    int size, capacity;
    int *buf;
} Heap;

int isFull(Heap *heap)
{
    return heap->size == heap->capacity;
}

int isEmpty(Heap *heap)
{
    return heap->size == 0 || heap->capacity == 0;
}

void printContents(const Heap *heap)
{
    if(heap == NULL)
    {
        return;
    }
    printf("The contents of the heap are: ");
    for(int i = 0; i < heap->size; i++)
    {
        printf(" %d",heap->buf[i]);
    }
}

Heap *percolateUp(Heap *heap, int n)
{
    if(n <= 0)
    {
        return heap;
    }
    else
    {
        if(heap->buf[(n-1)/2] > heap->buf[n])
        {
            int tmp = heap->buf[n];
            heap->buf[n] = heap->buf[(n-1)/2];
            heap->buf[(n-1)/2] = tmp;
        }
        return percolateUp(heap,(n-1)/2);
    }
}

Heap *percolateDown(Heap *heap, int n)
{
    int accessBoth = 0;
    if(n > heap->size - 1)
    {
        return heap;
    }
    else
    {
        if(heap->buf[n] > heap->buf[2*n+1] || heap->buf[n] > heap->buf[2*n + 2])
        {
            if(heap->buf[2*n + 1] > heap->buf[2*n + 2])
            {
                int tmp = heap->buf[n];
                heap->buf[n] = heap->buf[2*n + 2];
                heap->buf[2*n + 2] = tmp;
                return percolateDown(heap,2*n + 2);
            }
            else
            {
                int tmp = heap->buf[n];
                heap->buf[n] = heap->buf[2*n + 1];
                heap->buf[2*n + 1] = tmp;
                return percolateDown(heap,2*n + 1);
            }
        }
        return heap;
    }

    /*for(int i = 0; 2*i + 1 <= heap->size - 1 || 2*i + 2 <= heap->size - 1;)
    {
        if(2*i + 2 <= heap->size - 1)
        {
            accessBoth = 1;
        }
        else
        {
            accessBoth = 0;
        }
        if(accessBoth && (heap->buf[i] > heap->buf[2*i + 1] || heap->buf[i] > heap->buf[2*i + 2]))
        {
            if(heap->buf[2*i + 1] > heap->buf[2*i + 2])
            {
                int tmp = heap->buf[i];
                heap->buf[i] = heap->buf[2*i + 2];
                heap->buf[2*i + 2] = tmp;
                i = 2*i + 2;
            }
            else
            {
                int tmp = heap->buf[i];
                heap->buf[i] = heap->buf[2*i + 1];
                heap->buf[2*i + 1] = tmp;
                i = 2*i + 1;
            }
        }
        else if(heap->buf[i] > heap->buf[2*i + 1])
        {
            int tmp = heap->buf[i];
                heap->buf[i] = heap->buf[2*i + 1];
                heap->buf[2*i + 1] = tmp;
        }     
    }
    return heap;*/
}

Heap *buildHeap(int *sourceArray, int n)
{
    Heap *heap = (Heap *) malloc(sizeof(Heap));
    if(heap == NULL) return NULL;

    heap->buf = sourceArray;
    heap->capacity = heap->size = n;

    for(int i = 0; i < n - 1; i++)
    {
        heap = percolateDown(heap,i);
    }
    printContents(heap);
    return heap;
}

Heap *insertHeap(Heap *heap, int data)
{
    if(heap == NULL || isEmpty(heap)) return NULL;
    else if(isFull(heap)) 
    {
        printf("Heap capacity exceeded");
        return NULL;
    }
    else
    {
        heap->buf[heap->size] = data;
        heap->size++;
        
        heap = percolateUp(heap,heap->size - 1);
    }  
}

Heap *createHeap(int cap, int data)
{
    Heap *heap = (Heap *) malloc(sizeof(Heap));

    if(heap == NULL) return NULL;
    int *a = (int *) malloc(cap*sizeof(int));

    heap->buf = a;
    heap->capacity = cap;
    heap->size = 1;
    heap->buf[0] = data;
    printf("\n%d is in the heap",heap->buf[0]);
    return heap;
}

void printMin(const Heap *heap)
{
    printf("Minimum element: %d",heap->buf[0]);
}

Heap *deleteMin(Heap *heap)
{
    printf("Element being deleted: %d",heap->buf[0]);
    heap->buf[0] = heap->buf[heap->size - 1];
    heap->size--;
    heap = percolateDown(heap,0);

    return heap;
}

int main()
{
    int input,input2;
    Heap *heap = NULL;

    while(1){

    printf("1: Create Heap\t2: Insert\t3: Print min\n4: Delete min\t5: Print contents\t6: Build heap\nYour choice: ");
    scanf("%d",&input);

    switch(input)
    {
        case 1:
        printf("Enter capacity of heap required: ");
        scanf("%d",&input);
        printf("Enter data: ");
        scanf("%d",&input2);
        heap = createHeap(input,input2);
        if(heap == NULL) printf("Heap not created");
        break;

        case 2:
        printf("Enter element to be inserted: ");
        scanf("%d",&input);
        heap = insertHeap(heap,input);
        break;

        case 3:
        printMin(heap);
        break;

        case 4:
        heap = deleteMin(heap);
        break;

        case 5:
        printContents(heap);
        break;

        case 6:
        printf("Enter number of inputs: ");
        scanf("%d",&input);
        int *tmp_array = (int *) malloc(input*sizeof(int));
        printf("Enter %d elements, separated by spaces: ",input);
        for(int i = 0; i < input; i++)
        {
            scanf("%d",&tmp_array[i]);
        }
        heap = buildHeap(tmp_array, input);
        break;

        default:
        exit(1);
    }
    printf("\n");
    }
    return 0;
    //7029051174
}