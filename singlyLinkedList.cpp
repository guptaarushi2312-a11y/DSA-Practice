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

class SinglyLinkedList
{
    public:
    Node* head;

    SinglyLinkedList()
    {
        head = NULL;
    }

    //function to insert a value at the start
    void insertAtBeginning(int value)
    {
        Node* newNode = new Node(value);

        //base condition 
        if(head == NULL)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    //function to insert a value at the end 
    void insertAtEnd(int value)
    {
        Node* newNode = new Node(value);

        //base condition 
        if(head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node* temp = head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    //funtion to insert at a particular position 
    void insertAtPosition(int value,int position)
    {
        Node* newNode = new Node(value);
        
        //case 1: if position is at the start
        if(position == 1)
        {
            insertAtBeginning(value);
            return;
        }
        //otherwise
        Node* temp = head;

        for(int i=1;i<position-1 && temp != NULL;i++)
        {
            temp = temp->next;
        }
        if(temp == NULL)
        {
            cout<<"Position out of range...."<<endl;
            delete newNode;
            return;
        }
        else
        {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    //function to display the linked list
    void display()
    {
        //base condition
        if(head == NULL)
        {
            cout<<"Linked List is empty...."<<endl;
        }
        else 
        {
            Node* temp = head;
            while(temp != NULL)
            {
                cout<<temp->data<<"-->";
                temp = temp->next;
            }
            cout<<"NULL";
        }
    }

    //function to delete the first node
    void deleteFirst()
    {
        //base condition 
        if(head == NULL)
        {
            cout<<"Linked List is empty...."<<endl;
        }
        else
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    //function to delete the last node
    void deleteLast()
    {
        //base condition
        if(head == NULL)
        {
            cout<<"Linked List is empty....";
            return;
        } 
        if(head->next == NULL)
        {
            Node* temp = head;
            head = NULL;
            delete temp;
        }
        else
        {
            Node* curr = head;
            Node* prev = NULL;
            while(curr->next != NULL)
            {
                prev = curr;
                curr = curr->next;
            }
            prev->next = NULL;
            delete curr;
        }
    }

    //function to delete a particular Node 
    void deleteParticular(int position)
    {
        //case 1: if position is at the start
        if(position == 1)
        {
            deleteFirst();
            return;
        }
        //otherwise
        Node* curr = head;
        Node* prev = NULL;
    
        for(int i =1;i<position-1 && curr !=  NULL;i++)
        {
            prev = curr;
            curr = curr->next;
        }
        if(curr == NULL || curr->next == NULL)
        {
            cout<<"Position out of range...."<<endl;
            return;
        }
        prev->next = curr->next;
        delete curr;
    }
};

int main()
{
    SinglyLinkedList obj;
    int choice,value,position;
    do
    {
        /* code */
        cout<<endl;
        cout<<"1. Insert at the start...."<<endl;
        cout<<"2. Insert at the end...."<<endl;
        cout<<"3. Insert at a particular position...."<<endl;
        cout<<"4. Delete the first node...."<<endl;
        cout<<"5. Delete the last node...."<<endl;
        cout<<"6. Delete a particular node...."<<endl;
        cout<<"7. Display the Linked List...."<<endl;
        cout<<"8. Exit the program...."<<endl;
        cout<<endl;

        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
              cout<<"Enter value you want to insert: ";
              cin>>value;
              obj.insertAtBeginning(value);
              break;

            case 2:
              cout<<"Enter the value you want to insert: ";
              cin>>value;
              obj.insertAtEnd(value);
              break;

            case 3:
              cout<<"Enter the value you want to insert: ";
              cin>>value;
              cout<<endl;
              cout<<"Enter the position you want to insert at: ";
              cin>>position;
              obj.insertAtPosition(value,position);
              break;

            case 4:
              obj.deleteFirst();
              break;

            case 5:
              obj.deleteLast();
              break;
              
            case 6:
              cout<<"Enter the position at which you want to delete a node: ";
              cin>>position;
              obj.deleteParticular(position);
              break;
            
            case 7:
              obj.display();
              break;
 
            case 8:
              cout<<"Exiting...."<<endl;
              return 0;

            default:
              cout<<"Invalid choice entered !!";
              break;

        }
    } while (choice !=8 );
    return 0;
    
}
