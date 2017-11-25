#include <iostream>
using namespace std;
//Circular Linked List
//Mapua University
struct node {
    int data;
    node *next;
};
class list
{
private:
    node *head, *tail;
public:
    list() { head=NULL, tail=NULL;}
    void createnode(int value);
    void display();
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
    head=tail=temp;
}
void list::display()
{
    node *temp;
    temp=head;
    cout << "Linked List: ";
    while(temp->next!=head)
    {
        cout<<temp->data<<' ';
        temp=temp->next;
    }
    cout<<temp->data;
    cout<<endl;
}
void list::insert_start(int value)
{
    node *temp = new node;
    temp->data=value;
    if (head==NULL) {
        temp->next=NULL;
        head=tail=temp;
    } else {
        temp->next=head;
        head=temp;
        tail->next=head;
    }
}
void list::insert_end(int value)
{
    if (head==NULL) {
        cout << "List is empty" << endl;
    } else {
        node *temp= new node;
        temp->data=value;
        tail->next=temp;
        tail=temp;
        tail->next=head;
    }
}
void list::insert_position(int pos, int value)
{
    node *current, *prev_node;
    current=head;
    for(int i=1;i<pos&&current->next!=NULL;i++)
    {
        prev_node=current;
        current=current->next;
    }
    if (current->data==head->data) {
        cout << "Error: You're trying to change the head; Please use insert_start(int value) " << endl;
    }
    else if (current->data==tail->data) {
        cout << "Error: You're trying to change the tail; Please use insert_end(int value) " << endl;
    } else {
        node *temp= new node;
        temp->data=value;
        temp->next=current;
        prev_node->next=temp;
    }
}
void list::delete_head()
{
    node *temp;
    temp=head;
    head=head->next;
    tail->next=head;
    delete temp;
}
void list::delete_tail()
{
    node *current, *prev_node;
    current=head;
    prev_node=NULL;
    while(current->next!=head)
    {
        prev_node=current;
        current=current->next;
    }
    tail=prev_node;
    tail->next=head;
    delete current;
}
void list::delete_position(int pos)
{
    node *current, *prev_node, *next_node;
    current=head;
    next_node=current->next;
    prev_node=NULL;
    for(int i=1;(i<pos&&current->next!=NULL);i++)
    {
        prev_node=current;
        current=current->next;
        next_node=current->next;
    }
    if (current->data==head->data) {
        cout << "Error: You're trying to change the head; Please use delete_start(int value) " << endl;
    } else if (current->data==tail->data) {
        cout << "Error: You're trying to change the head; Please use delete_end(int value) " << endl;
    } else {
        prev_node->next=next_node;
        delete current;
    }
}
int main() {
    list *a = new list;
    a->createnode(9);
    a->insert_start(1);
    a->insert_start(2);
    a->insert_end(3);
    a->insert_position(2, 4);
    a->display();
    a->delete_head();
    a->display();
    a->delete_tail();
    a->display();
    a->insert_end(5);
    a->display();
    a->delete_position(2);
    a->display();
    a->insert_position(2, 7);
    a->display();
    a->insert_position(3, 8);
    a->display();
    a->insert_end(6);
    a->display();
    a->insert_start(1);
    a->display();
    return 0;
}