#include <iostream>
using namespace std;
//Singly Linked List
//Mapua University
struct node {
    int data;
    node *next;
    node *prev;
};
class list
{
private:
    node *head, *tail;
public:
    list()
    {
        head=NULL;
        tail=NULL;
    }
    void createnode(int value);
    void display();
    void insert_start(int value);
    void insert_position(int pos, int value);
    void delete_first();
    void delete_last();
    void delete_position(int pos);
};
void list::createnode(int value)
{
    node *temp=new node;
    temp->data=value;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
        tail=temp;
    }
    else
    {
        tail->next=temp;
        tail=temp;
    }
}
void list::display()
{
    node *temp;
    temp=head;
    cout << "Linked List: ";
    while(temp!=NULL)
    {
        cout<<temp->data<<' ';
        temp=temp->next;
    }
    cout<<endl;
}
void list::insert_start(int value)
{
    node *temp=new node;
    temp->data=value;
    temp->next=head;
    head=temp;
}
void list::insert_position(int pos, int value)
{
    node *pre=new node;
    node *cur;
    node *temp=new node;
    cur=head;
    for(int i=1;i<pos;i++)
    {
        pre=cur;
        cur=cur->next;
    }
    temp->data=value;
    pre->next=temp;
    temp->next=cur;
}
void list::delete_first()
{
    node *temp;
    temp=head;
    head=head->next;
    delete temp;
}
void list::delete_last()
{
    node *current;
    node *previous=new node;
    current=head;
    while(current->next!=NULL)
    {
        previous=current;
        current=current->next;
    }
    tail=previous;
    previous->next=NULL;
    delete current;
}
void list::delete_position(int pos)
{
    node *current;
    node *previous=new node;
    current=head;
    for(int i=1;i<pos;i++)
    {
        previous=current;
        current=current->next;
    }
    previous->next=current->next;
}
int main() {
    list *a = new list;
    a->createnode(10);
    a->display();
    a->delete_first();
    a->insert_start(12);
    a->display();
    a->insert_position(2,13);
    a->display();
    a->delete_last();
    a->insert_position(2,13);
    a->insert_position(3,14);
    a->insert_position(4,15);
    a->display();
    a->delete_position(3);
    a->display();
    return 0;
}