#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class CircularLinkedList
{  
    public:
    Node* head;

    CircularLinkedList()
    {
        head = NULL;
    }

    void insertAtStart(int value)
    {
        Node* newNode = new Node(value);
        if(head == NULL)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            Node* temp = head;
            while(temp->next != head)
            {
                temp = temp->next;
            }
            newNode->next = head;
            head = newNode;
            temp->next = head;
        }
    }

    void insertAtLast(int value)
    {
        Node* newNode = new Node(value);
        if(head == NULL)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            Node* temp = head;
            while(temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void insertAtParticular(int value,int position)
    {
        if(head == NULL || position == 1)
        {
            insertAtStart(value);
            return;
        }
        else
        {
            Node* temp = head;
            int count = 1;
            while(count<position-1 && temp->next != head)
            {
                temp = temp->next;
                count++;
            }
            if(temp->next == head)
            {
                insertAtLast(value);
                return;
            }
            else
            {
                Node* newNode = new Node(value);
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
    }

    void deleteFirst()
    {
        if(head == NULL)
        {
            cout<<"Linked List is empty...."<<endl;
            return;
        }
        else
        {
            Node* temp = head;
            Node* delNode = head;
            while(temp->next != head)
            {
                temp = temp->next;
            }
            head = head->next;
            temp->next = head;
            delete delNode;
        }
    }

    void deleteLast()
    {
        if(head == NULL)
        {
            cout<<"Linked List is empty...."<<endl;
            return;
        }
        else 
        {
            Node* curr = head;
            Node* prev = NULL;
            while(curr->next != head)
            {
                prev = curr;
                curr = curr->next;
            }
            prev->next = head;
            delete curr;

        }
    }

    void deleteParticular(int position)
    {
        if(position == 1)
        {
            deleteFirst();
            return;
        }
        else
        {
            Node* temp = head;
            Node* prev = NULL;
            while(--position)
            {
               prev = temp;
               temp = temp->next;
            }
            if(temp->next == head)
            {
               deleteLast();
            }
            else
            {
               prev->next = temp->next;
               delete temp;
            }
        }
    }

    void display()
    {
        if(head == NULL)
        {
            cout<<"Linked List is empty...."<<endl;
            return;
        }
        else
        {
            Node* temp = head;
            while(temp->next != head)
            {
               cout<<temp->data<<"-->>";
               temp = temp->next;
            }
            cout<<temp->data<<"-->";
            cout<<"(Back to head)";
        }
    }
};

int main()
{
    CircularLinkedList obj;
    int choice,value,position;
    do
    {
        /* code */
        cout<<endl;
        cout<<"1. Insert at start...."<<endl;
        cout<<"2. Insert at last...."<<endl;
        cout<<"3. Insert at a particular position...."<<endl;
        cout<<"4. Delete at start...."<<endl;
        cout<<"5. Delete at last...."<<endl;
        cout<<"6. Delete at a particular position...."<<endl;
        cout<<"7. Display the linked list...."<<endl;
        cout<<"8. Exit the program...."<<endl;

        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
            cout<<"Enter the value you want to insert: ";
            cin>>value;
            obj.insertAtStart(value);
            break;

            case 2:
            cout<<"Enter the value you want to insert: ";
            cin>>value;
            obj.insertAtLast(value);
            break;

            case 3:
            cout<<"Enter the value you want to insert: ";
            cin>>value;
            cout<<endl;
            cout<<"Enter the position you want the value to be inserted at: ";
            cin>>position;
            obj.insertAtParticular(value,position);
            break;

            case 4:
            obj.deleteFirst();
            break;

            case 5:
            obj.deleteLast();
            break;

            case 6:
            cout<<"Enter the position you want to delete the node at: ";
            cin>>position;
            obj.deleteParticular(position);
            break;

            case 7:
            obj.display();
            break;

            case 8:
            cout<<"Exiting the program...."<<endl;
            return 0;

            default:
            cout<<"Invalid choice...."<<endl;
            break;

        }
    } while (choice != 8);
    return 0;
}
