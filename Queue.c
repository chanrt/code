#include<stdio.h>
#include<stdlib.h>

typedef struct queue
{
    int *array;
    int left, right;
    int size,capacity;
} Queue;

int isFull(Queue *queue)
{
    return (queue->size == queue->capacity);
}

int isEmpty(Queue *queue)
{
    return (queue->size == 0 || queue == NULL);
}

Queue *makeQueue(int cap)
{
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    if(queue == NULL)
    {
        printf("Unable to create queue");
        exit(1);
    }

    int *p = (int *) malloc(cap*sizeof(int));
    queue->array = p;
    queue->capacity = cap;
    queue->size = 0;
    queue->left = 0;
    queue->right = -1;

    return queue;
}

void printQueue(Queue *queue)
{
    if(queue == NULL || queue->size == 0)
    {
        printf("Queue has not been created yet, or is empty");
        return;
    }

    printf("The contents of the queue are: ");
    for(int i = queue->left; i <= queue->right; i++)
    {
        printf("%d ",queue->array[i]);
    }
}

Queue *enQueue(Queue *queue, int n)
{
    if(isFull(queue))
    {
        printf("Queue is full, more elements cannot be inserted");
        return queue;
    }
    queue->right = (++queue->right) % queue->capacity;
    queue->array[queue->right] = n;
    queue->size++;

    return queue;
}

Queue *deQueue(Queue *queue)
{
    int tmp;
    if(isEmpty(queue))
    {
        printf("Queue is empty or has not been created yet");
        return queue;
    }
    tmp = queue->array[queue->left];
    queue->left++;
    queue->size--;
    printf("Element dequeued is %d",tmp);

    return queue;
}

Queue *makeEmpty(Queue *queue)
{
    queue->left = - 1;
    queue->right = 0;
    queue->size = 0;
    
    return queue;
}

Queue *deleteQueue(Queue *queue)
{
    free(queue);
    return NULL;
}

void main()
{
    Queue *queue = NULL;
    int input,input1;
    while(1)
    {
        printf("1: Create queue\t2: Print queue\t3: Enqueue\n4: Dequeue\t5: Empty queue\t6: Delete queue\nYour Choice: ");
        scanf("%d",&input);

        switch(input)
        {
            case 1:
            printf("Enter capacity of queue: ");
            scanf("%d",&input1);
            queue = makeQueue(input1);
            break;

            case 2:
            printQueue(queue);
            break;

            case 3:
            printf("Enter element to be inserted: ");
            scanf("%d",&input1);
            queue = enQueue(queue, input1);
            break;

            case 4:
            queue = deQueue(queue);
            break;

            case 5:
            queue = makeEmpty(queue);
            break;

            case 6:
            queue = deleteQueue(queue);

            default:
            exit(1);
        }
        printf("Left: %d, Right: %d, Size: %d",queue->left,queue->right,queue->size);
        printf("\n");
    }
}