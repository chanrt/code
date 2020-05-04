#include<iostream>
#include<conio.h>

#include"Graphics_handler.cpp"
#include"Linked_list_class.cpp"

using namespace std;

class ListSim : public List
{
    public:
        void printNodes(int index)
        {
            if(list != NULL)
            {
                node *p = list;
                wipeArea(3,18,109,26);
                for(int i = 1; i <= 6; i++) drawVertical(3+(15*i),18,26);

                for(int i = 1; i < index; i++,p = p->next);
                for(int j = 0; j <= 6; j++, p = p->next)
                {
                    if(p == NULL) break;

                    gotoxy(4+(j*15),18);
                    printf("Index: %d",index+j);

                    gotoxy(4+(j*15),20);
                    printf("Node address:");
                    gotoxy(4+(j*15),21);
                    printf("%d",p);
                    gotoxy(4+(j*15),23);
                    printf("Node->data:%d",p->data);
                    gotoxy(4+(j*15),25);
                    printf("Node->next:");
                    gotoxy(4+(j*15),26);
                    printf("%d",p->next);
                }
            }
        }
        void simPrepend(int d)
        {
            gotoxy(3,32);
            printf("New node with address %d was created",list);
            gotoxy(3,33);
            printf("It's data was initialised to %d",d);
            gotoxy(3,34);
            printf("It's next node address was initialised to %d",list->next);
            gotoxy(3,35);
            printf("(The address of the initial node previously)");

            gotoxy(3,37);
            printf("Press any key to continue");
            getch();
            for(int i = 32; i < 38; i++) wipeLine(i);
        }
        void simAppend(int d)
        {
            node *p = list;

            gotoxy(3,27);
            printf("(Current node)");
            gotoxy(3,33);
            printf("OPERATION: Append a node with element %d",d);
            gotoxy(3,34);
            printf("CONDITION: node->next is 0 (NULL)");
            delay(3);

            for(int i = 1; i <= numElements(); i++, p = p->next)
            {
                if(i != 1) printNodes(i);
                gotoxy(3,36);
                printf("For current node - EVALUATES TO: ");
                delay(2);

                if(p->next == NULL)
                {
                    printf("True");
                    delay(2);
                    gotoxy(3,37);
                    printf("Node node is created. It's data is assigned to %d and next->node is assigned to NULL",d);
                    gotoxy(3,38);
                    printf("The next->node of last node is assigned to address of the new node");
                    gotoxy(3,39);
                    printf("Press any key to continue");
                    getch();
                    wipeLine(27);
                    for(int i = 33; i < 39; i++) wipeLine(i);
                    break;
                }
                else
                {
                    printf("False (Going to next node in a second)");
                }

                delay(4);
                wipeLine(36);
            }
        }
};

int main()
{
    ListSim list;

    drawLayout();
    int choice, data, node_num;

    while(1)
    {
        gotoxy(3,5);
        cout<<"TASKS: ";
        gotoxy(10,5);
        if(list.Created()) cout<<"1: Delete linked list";
        else cout<<"1: Create linked list";
        gotoxy(10,6);
        cout<<"2: Print linked list";
        gotoxy(10,7);
        cout<<"3: Prepend element";
        gotoxy(10,8);
        cout<<"4: Append element";
        gotoxy(10,9);
        cout<<"5: Insert element after n-th node";
        gotoxy(10,10);
        cout<<"6: Number of elements";
        gotoxy(10,11);
        cout<<"7: Delete n-th node";
        gotoxy(10,12);
        cout<<"8: Delete node with given element";
        gotoxy(3,14);
        cout<<"Your choice: ";
        cin>>choice;

        gotoxy(3,15);
        if(choice == 1)
        {
            if(!list.Created())
            {
                cout<<"Enter data: ";
                cin>>data;
                list.createList(data);
            }
            else{
                list.deleteList();
                cout<<"List deleted";
                delay(1);
            }
        }
        else if(choice == 2)
        {
            if(list.Created())
            {
                cout<<"Elements: ";
                gotoxy(13,15);
                list.printList();
                gotoxy(3,16);
                cout<<"Press any key to continue";
                getch();
            }
            else
            {
                printf("Linked list not created yet");
                delay(2);
            }
        }
        else if(choice == 3)
        {
            if(list.Created())
            {
                cout<<"Enter data: ";
                cin>>data;
                list.prepend(data);
                list.simPrepend(data);
            }
            else
            {
                printf("Linked list not created yet");
                delay(2);
            }
        }
        else if(choice == 4)
        {
            if(list.Created())
            {
                cout<<"Enter data: ";
                cin>>data;
                list.simAppend(data);
                list.append(data);
            }
            else
            {
                printf("Linked list not created yet");
                delay(2);
            }
        }
        else if(choice == 5)
        {
            if(list.Created())
            {
                cout<<"Enter node index after which element is to be inserted: ";
                cin>>node_num;
                gotoxy(3,16);
                if(node_num >= 0 && node_num <= list.numElements())
                {
                    cout<<"Enter data: ";
                    cin>>data;

                    if(node_num == 0) list.prepend(data);
                    else if(node_num == list.numElements()) list.append(data);
                    else list.insertAfter(data,node_num);
                }
                else
                {
                    printf("Please enter a valid node index");
                    delay(2);
                }
            }
            else
            {
                printf("Linked list not created yet");
                delay(2);
            }
        }
        else if(choice == 6)
        {
            if(list.Created()) cout<<"Number of elements in linked list is: "<<list.numElements();
            else printf("Linked list not created yet\n"); 
            delay(2);
        }
        else if(choice == 7)
        {
            if(list.Created())
            {
                cout<<"Enter node index to be deleted: ";
                cin>>node_num;
                gotoxy(3,16);
                if(node_num >= 0 && node_num <= list.numElements()) list.deleteNode(node_num);
                else
                {
                    printf("Please enter a valid node index");
                    delay(2);
                }
            }
            else
            {
                printf("Linked list not created yet");
                delay(2);
            }
        }
        else if(choice == 8)
        {
            if(list.Created())
            {
                cout<<"Enter element to be deleted: ";
                cin>>data;
                list.deleteElement(data);
            }
            else
            {
                printf("Linked list not created yet");
                delay(2);
            }
        }
        wipeLine(14);
        wipeLine(15);
        wipeLine(16);

        if(list.Created())
        {
            list.printNodes(1);
        }
    }
}