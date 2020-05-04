#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} List;

List* buildList()
{
    List *list = (List *) malloc(sizeof(List));

    if(list == NULL)
    {
        printf("Build list failed");
        exit(1);
    }

    else
    {
        int dat;
        printf("Enter data: ");
        scanf("%d",&dat);

        list->data = dat;
        list->next = NULL;
    }

    return list;
}

void printList(List *list)
{
    if(list == NULL)
    {
        printf("List does not exist yet");
    }

    else
    {
        printf("Contents of the list: ");
        while(list != NULL)
        {
            printf("%d ",list->data);
            list = list->next;
        }
    } 
    printf("\n");
}

void deleteList(List *list)
{
    List *temp;

    if(list == NULL)
    {
        printf("List does not exist yet");
    }

    else
    {
        while(list != NULL)
        {
            temp = list;
            list = list->next;
            free(temp);
        }
        printf("List deleted");
    } 
    printf("\n");
}

List* prependList(List *list)
{
    List *new_node = (List *) malloc(sizeof(List));

    if(new_node == NULL)
    {
        printf("Failure in prepending list");
    }

    else
    {
        int dat;

        printf("Enter data: ");
        scanf("%d",&dat);

        new_node->data = dat;
        new_node->next = list;
        list = new_node;

        return list;
    }  
}

List* appendList(List *list)
{
    if(list == NULL)
    {
        printf("List does not exist yet");
    }

    else
    {
        List *new_node = (List *) malloc (sizeof(List));
        List *p = list;

        if(new_node == NULL)
        {
            printf("Failure in appending list");
            return list;
        }

        int dat;
        printf("Enter data: ");
        scanf("%d",&dat);

        while(list->next != NULL)
        {
            list = list->next;
        }

        new_node->data = dat;
        new_node->next = NULL;
        list->next = new_node;

        return p;
    }
}

void findElement(List *list)
{
    if(list == NULL)
    {
        printf("List does not exist yet");
    }

    else
    {
        int search, isFound = 0;
        printf("Type element to be searched: ");
        scanf("%d",&search);
        for(int index = 1; list != NULL; list=list->next, index++)
        {
            if(list->data == search)
            {
                printf("Element = %d found at position %d\n",search,index);
                isFound = 1;
            }
        }
        
        if(!isFound)
        {
            printf("Element = %d not found\n",search);
        }
    }
}

void sizeOf(List *list)
{
    int size;

    if(list == NULL)
    {
        printf("List does not exist yet");
    }

    else
    {
        for(size = 0; list != NULL; list = list->next, size++);
        printf("The list has %d elements\n",size);
    }
}

void searchNode(List *list)
{
    if(list == NULL)
    {
        printf("List does not exist yet");
    }

    else
    {
        int index;
        printf("Type position to be searched (first element is counted as 1): ");
        scanf("%d",&index);

        for(int i = 1; i < index && (list->next) != NULL; i++,list = list->next);
    
        printf("The element in position %d is %d",index,list->data);
        printf("\n");
    }
}

void predecessorOf(List *list)
{
    if(list == NULL)
    {
        printf("List does not exist yet");
    }

    else
    {
        List *p = list;
        int preData = 0;
        int search;
        printf("Enter element whose predecessor is to be found: ");
        scanf("%d",&search);

        if(list->data == search)
        {
            printf("Element occurs at the first position, hence it has no predecessor");
            return ;
        }
        preData = list->data;

        for(list = list->next ; list != NULL ; list = list->next);
        {
            if(list->data == search);
            {
                printf("Element that is predecessor of %d is %d",search,preData);
            }
            preData = list->data;
        }

    }
}

List* deleteNode(List *list, int pos)
{
    if(list == NULL)
    {
        printf("List does not exist yet");
    }
    else
    {
        List *p = list;

        for(int index = 1; index < (pos-1); index++, list = list->next)
        {
            if(list == NULL)
            {
                printf("That index does not exist in the list");
                free(p);
                return list;
            }
        }
        List *head = list;
        List *tail =(list->next)->next;
        free(list->next);
        head->next = tail;

        return p;
    }
    
}

List* insertNode(List *list, int pos, int dat)
{
    if(list == NULL)
    {
        printf("List has not been created yet");
    }

    else
    {
        List *p = list;
        List *new_node = (List *) malloc(sizeof(List));

        if(new_node == NULL)
        {
            printf("Unable to insert element");
            free(p);
            return list;
        }

        for(int index = 1; index < pos-1; list =  list->next, index++)
        {
            if(list == NULL)
            {
                printf("That index is not available, use append");
                free(p);
                return list;
            }
        }
        List *tail = list->next;

        list->next = new_node;
        new_node->data = dat;
        new_node->next = tail;

        return p;
    }
    
}

int main()
{
    List *list;
    int input, input1, input2;

    list = NULL;

    while(1)
    {
        printf("\n1: Create linked list\t2: Print list\t3: Delete entire list\n4: Prepend\t5: Append\t6: Find\n7: Size\t8: Search Node\t9: Search predecessor of\n10: Insert at\t11: Delete Node\nYour choice: ");
        scanf("%d",&input);

        switch(input)
        {
            case 0:
            default:
            exit(1);
            break;

            case 1:
            list = buildList();
            break;

            case 2:
            printList(list);
            break;

            case 3:
            deleteList(list);
            break;

            case 4:
            list = prependList(list);
            break;

            case 5:
            list = appendList(list);
            break;

            case 6:
            findElement(list);
            break;

            case 7:
            sizeOf(list);
            break;

            case 8:
            searchNode(list);
            break;

            case 9:
            predecessorOf(list);
            break;

            case 10:
            printf("Type position: ");
            scanf("%d",&input1);
            printf("Type data: ");
            scanf("%d",&input2);
            list = insertNode(list, input1, input2);
            break;

            case 11:
            printf("Type position to delete: ");
            scanf("%d",&input1);
            list = deleteNode(list, input1);
            break;
        }
    }

}