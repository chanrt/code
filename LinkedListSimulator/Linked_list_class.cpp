#include<iostream>

using namespace std;

typedef struct Node
{
    int data;
    Node *next;
} node;

class List
{
    protected:
        node *list;

    public:
        List()
        {
            list = NULL;
        }

        bool Created()
        {
            if(list == NULL) return false;
            else return true;
        }

        void createList(int d)
        {
            list = new node;
            list->data = d;
            list->next = NULL;
        }

        void deleteList()
        {
            node *p = list, *temp;

            while(p != NULL)
            {
                temp = p;
                p = p->next;
                delete temp;
            }
            list = NULL;
        }

        void prepend(int d)
        {
            node *q = new node;
            
            q->data = d;
            q->next = list;
            list = q;
        }

        void append(int d)
        {
            node *p, *q;
            p = list;

            while(p->next != NULL)
            {
                p = p->next;
            }

            q = new node;
            q->data = d;
            q->next = NULL;
            p->next = q;
        }

        void printList()
        {
            node *p;
            p = list;

            while(p != NULL)
            {
                printf("%d ",p->data);
                p = p->next;
            }
            cout<<endl;
        }

        int numElements()
        {
            int num;
            node *p = list;

            for(num = 0; p != NULL; num++, p = p->next);
            return num;
        }

        void insertAfter(int d, int node_num)
        {
            int num;
            node *p = list, *q;

            for(num = 1; num != node_num; num++, p = p->next);
            
            q = new node;
            q->data = d;
            q->next = p->next;
            p->next = q;
        }

        void deleteNode(int node_num)
        {
            node *temp;

            if(node_num == 1)
            {
                temp = list;
                list = list->next;
                delete temp;
            }
            else
            {
                node *p = list;
                for(int num = 1; num < (node_num - 1); num++, p = p->next);
                temp = p->next;
                p->next = (p->next)->next;
                delete temp;
            }
        }

        void deleteElement(int d)
        {
            node *temp;

            if(list->data == d)
            {
                temp = list;
                list = list->next;
                delete temp;
            }
            else
            {
                node *p = list;
                for(; (p->next)->data != d; p = p->next)
                {
                    if(p == NULL) break;
                }
                temp = p->next;
                p->next = (p->next)->next;
                delete temp;
            }
        }
};
