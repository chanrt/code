#include<iostream>

using namespace std;

class Stack
{
    private:
        int *arr;
        int top;
        int max;

    public:
        Stack(int n)
        {
            arr = new int[n];

            if(arr == NULL)
            {
                cout<<"Memory space cannot be allocated";
                exit(1);
            }
            top = -1;
            max = n;
        }

        Stack()
        {
            int max = 10;
            top = -1;

            arr = new int[max];
        }

        void push(int i)
        {
            if(top == (max - 1)) cout<<"Queue is full";
            else
            {
                arr[++top] = i;
            }
        }

        int pop()
        {
            if(top == -1)
            {
                cout<<"Queue is empty";
            }
            else
            {
                return arr[top--];
            }
        }

        void printStack()
        {
            if(top == -1) cout<<"Queue is empty";
            else
            {
                for(int i = 0; i <= top; i++)
                {
                    cout<<endl<<arr[i];
                }
            }
        }
};

int main()
{
    int n;
    cout<<"Enter max number of elements: ";
    cin>>n;

    Stack q(n);

    while(1)
    {
        int choice;
        cout<<endl<<"1: Push"<<endl<<"2: Pop"<<endl<<"3: Print stack"<<endl<<"Enter choice: ";
        cin>>choice;

        if(choice == 1)
        {
            int i;
            cout<<endl<<"Enter element: ";
            cin>>i;
            q.push(i);
        }
        else if(choice == 2)
        {
            int i = q.pop();
            cout<<"The element is "<<i;
        }
        else
        {
            q.printStack();
        }
    }
}