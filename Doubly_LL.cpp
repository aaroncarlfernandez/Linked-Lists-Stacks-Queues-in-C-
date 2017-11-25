#include <iostream>
using namespace std;
//Doubly Linked List
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
    list() { head=NULL, tail=NULL;}
    void createnode(int value);
    void display();
    void display_reverse();
    void insert_start(int value);
    void insert_end(int value);
    void insert_position(int pos, int value);
    void delete_head();
    void delete_tail();
    void delete_position(int pos);
};
void list::createnode(int value)
{
    node *temp=new node;
    temp->data=value;
    temp->next=NULL;
    temp->prev=NULL;
    head=tail=temp;
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
void list::display_reverse()
{
    node *temp;
    temp=tail;
    cout << "Linked List in reverse: ";
    while(temp!=NULL)
    {
        cout<<temp->data<<' ';
        temp=temp->prev;
    }
    cout<<endl;
}
void list::insert_start(int value)
{
    if (head==NULL) {
        cout << "List is empty" << endl;
    }
    else {
        node *temp = new node;
        temp->data=value;
        temp->next=head;
        temp->prev=NULL;
        head->prev=temp;
        head=temp;
    }
}
void list::insert_end(int value)
{
    if (head==NULL) {
        cout << "List is empty" << endl;
    } else {
        node *temp= new node;
        temp->data=value;
        temp->next=NULL;
        temp->prev=tail;
        tail->next=temp;
        tail=temp;
    }
}
void list::insert_position(int pos, int value)
{
    node *current, *prev_node;
    current=head;
    prev_node=current->prev;
    for(int i=1;i<pos&&current->next!=NULL;i++)
    {
        current=current->next;
        prev_node=current->prev;
    }
    if (current->data==head->data) {
        cout << "Error: You're trying to change the head; Please use insert_start(int value) " << endl;
    }
    else if (current->data==tail->data) {
        cout << "Error: You're trying to change the tail; Please use insert_end(int value) " << endl;
    } else {
        node *temp= new node;
        temp->data=value;
        temp->prev=prev_node;
        temp->next=current;
        prev_node->next=temp;
        current->prev=temp;
    }
}
void list::delete_head()
{
    node *temp;
    temp=head;
    head=head->next;
    head->prev=NULL;
    delete temp;
}
void list::delete_tail()
{
    node *temp;
    temp=tail;
    tail=tail->prev;
    tail->next=NULL;
    delete temp;
}
void list::delete_position(int pos)
{
    node *current, *prev_node, *next_node;
    current=head;
    prev_node=current->prev;
    next_node=current->next;
    for(int i=1;(i<pos&&current->next!=NULL);i++)
    {
        current=current->next;
        prev_node=current->prev;
        next_node=current->next;
    }
    if (current->data==head->data) {
        cout << "Error: You're trying to change the head; Please use delete_start(int value) " << endl;
    } else if (current->data==tail->data) {
        cout << "Error: You're trying to change the head; Please use delete_end(int value) " << endl;
    } else {
        prev_node->next=next_node;
        next_node->prev=prev_node;
        delete current;
    }
}
int main() {
    list *a = new list;
    a->createnode(1);
    a->insert_start(2);
    a->insert_start(3);
    a->insert_start(4);
    a->insert_end(9);
    a->display();
    a->delete_head();
    a->display();
    a->delete_tail();
    a->display();
    a->insert_position(2,7);
    a->display();
    a->delete_position(3);
    a->display();
    a->display_reverse();
    return 0;
}