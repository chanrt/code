#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct node 
{
    int data;
    struct node *left;
    struct node *right;
} Tree;

Tree* buildTree(int dat)
{
    Tree *tree = (Tree *) malloc(sizeof(Tree));

    if(tree == NULL)
    {
        printf("Failed to create tree");
        exit(1);
    }

    tree->data = dat;
    tree->left = NULL;
    tree->right = NULL;

    return tree;
}

Tree* insertElement(Tree *tree, int dat)
{
    if(tree == NULL)
    {
        printf("The tree has not yet been created");
    }

    else
    {

    Tree *p = tree;
    Tree *new_node = (Tree *) malloc(sizeof(Tree));

    while(1)
    {
        if(tree->data > dat)
        {
            if(tree->left != NULL)
            {
                tree = tree->left;
            }
            else
            {
                tree->left = new_node;
                new_node->data = dat;
                new_node->left = NULL;
                new_node->right = NULL;

                return p;
            }           
        }
        else if(tree->data < dat)
        {
            if(tree->right != NULL)
            {
                tree = tree->right;
            }
            else
            {
                tree->right = new_node;
                new_node->data = dat;
                new_node->left = NULL;
                new_node->right = NULL;

                return p;
            }       
        }
        else
        {
            printf("Error in inserting element");
            break;
        }       
    }
    }
}

void printTree(Tree *tree)
{
    if(tree != NULL)
    {
        printTree(tree->left);
        printf("%d ",tree->data);
        printTree(tree->right);
    }
}

void findBetween(Tree *tree, int lower, int upper)
{
    if(tree != NULL)
    {
        findBetween(tree->left, lower, upper);
        if(lower <= tree->data && tree->data <= upper)
        {
            printf("%d ",tree->data);
        }      
        findBetween(tree->right, lower, upper);
    }
    else;
}

int findMin(Tree *tree)
{
    if(tree->left == NULL)
    {
        return tree->data;
    }
    return findMin(tree->left);
}

int findMax(Tree *tree)
{
    if(tree->right == NULL)
    {
        return tree->data;
    }
    return findMax(tree->right);
}

int find(Tree *tree, int dat)
{
    if(tree == NULL)
    {
        return 0;
    }
    else
    {
        if(tree->data == dat)
        {
            return 1;
        }
        else
        {
            if(tree->data > dat)
            {
                return find(tree->left,dat);
            }
            else return find(tree->right,dat);
        }
    }
    
}

int maxHeapProperty(Tree *tree)
{
    if(tree != NULL)
    {
        return maxHeapProperty(tree->left);
        if(tree->data < (tree->left)->data || tree->data < (tree->right)->data)
        {
            return 0;
        }
        return maxHeapProperty(tree->right);
        return 1;
    }
}

int maxHeapStructure(Tree *tree)
{
}

int delete(Tree *tree,int dat)
{
    if(tree == NULL)
    {
        return 0;
    }
    if(tree->data > dat) delete(tree->left, dat);
    else if(tree->data < dat) delete(tree->right, dat);
    else
    {
        if(tree->left != NULL && tree->right != NULL)
        {
            Tree *p = tree;
            p = p->right;

            while(p != NULL)
            {
                p = p->left;
            }
            tree->data = p->data;
            delete(p,tree->data);
            return 1;
        }
        else if(tree->left != NULL)
        {
            Tree *p = tree;
            p = p->left;
            tree->data = p->data;
            delete(p,tree->data);
        }
        else
        {
            Tree *p = tree;
            p = p->right;
            tree->data = p->data;
            delete(p,tree->data);
        }
        
    }
}

int numNodes(Tree *tree)
{
    if(tree != NULL)
    {
        return numNodes(tree->left) + numNodes(tree->right) + 1;
    }
}

int depthTree(Tree *tree)
{
    if(tree != NULL)
    {
        return 1 + depthTree(tree->left);
    }
}

int main()
{
    Tree *tree = NULL;
    int input1, input2;
    int output;

    while(1)
    {
        printf("\n1: Create tree\t2: Insert\t3: Print tree\n4: Find max\t5: Find min\t6: Find\n7: Delete\t8: Predecessor\t9: Successor\n10: Find between\t11: MaxHeap property\n12: MaxHeap structure\t13: Number of nodes\n14: Depth of tree\nYour choice: ");
        scanf("%d",&input1);

        switch(input1)
        {
            case 1:
            printf("Enter data: ");
            scanf("%d",&input2);
            tree = buildTree(input2);
            break;

            case 2:
            printf("Enter data: ");
            scanf("%d",&input2);
            tree = insertElement(tree, input2);
            break;

            case 3:
            if(tree == NULL)
            {
                printf("Tree has not been created yet");
            }
            else
            {
                printf("The elements in the tree are: ");
                printTree(tree);
            }  
            break;

            case 4:
            if(tree == NULL)
            {
                printf("Tree has not been created yet");
            }
            else
            {
                output = findMin(tree);
                printf("Minimum element is: %d",output);
            }
            break;

            case 5:
            if(tree == NULL)
            {
                printf("Tree has not been created yet");
            }
            else
            {
                output = findMax(tree);
                printf("Maximum element is: %d",output);
            }
            break;

            case 6:
            printf("Type element to be searcher: ");
            scanf("%d",&input1);
            if(tree == NULL)
            {
                printf("Tree has not been created yet");
            }
            else 
            {
                output = find(tree,input1);
                if(output == 0)
                {
                    printf("%d doesn't exist in the tree",input1);
                }
                else
                {
                    printf("%d exists in the tree",input1);
                }
            }
            break;

            case 7:
            if(tree == NULL)
            {
                printf("Tree doesn't exist yet");
            }
            else
            {
                printf("Enter element to be deleted: ");
                scanf("%d",&input1);
                output = delete(tree,input1);   
                if(output == 1)
                {
                    printf("%d has been deleted from the tree",input1);
                }         
                else
                {
                    printf("%d didn't exist in the tree",input1);
                }
            }
            break;

            case 8:
            break;

            case 9:
            break;

            case 10:
            printf("Enter lower bound: ");
            scanf("%d",&input1);
            printf("Enter upper bound: ");
            scanf("%d",&input2);
            findBetween(tree, input1, input2);
            break;

            case 11:
            input1 = maxHeapProperty(tree);
            if(input1 == 1)
            {
                printf("Binary tree has max heap property");
            }
            else printf("Binary tree does not have max heap property");
            break;

            case 12:
            input1 = numNodes(tree);
            input2 = depthTree(tree) - 1;
            printf("Binary tree has binary heap strcuture: %d",((pow(2,input2) <= input1) && (input1 <= (pow(2,input2) - 1))));
            break;

            case 13:
            input1 = numNodes(tree);
            printf("The number of nodes in the tree is %d",input1);
            break;

            case 14:
            printf("The depth of the tree is %d",depthTree(tree) - 1);
            break;

            default:
            exit(1);
        }
    }
}