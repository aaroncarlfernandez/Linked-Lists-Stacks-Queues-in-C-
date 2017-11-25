#include <iostream>
using namespace std;
//Queues using Linked Lists
//Mapua University
struct node {
    int data;
    node *next;
};
class list
{
private:
    node *front, *rear;
public:
    list()
    {
        front=NULL;
        rear=NULL;
    }
    void enqueue(int new_data);
    int dequeue();
};



void list::enqueue(int new_data) {
    node *temp = new node;
    temp->data = new_data;
    temp->next=NULL;
    if (front==NULL) {
        front = rear = temp;
        rear->next=NULL;
    } else {
        rear->next=temp;
        rear=temp;
        rear->next=NULL;
    }
}

int list::dequeue() {
    if (front==NULL) {
        cout << "You cannot dequeue an empty queue!" << endl;
        exit(1);
    } else {
        node *oldhead = front;
        int value = oldhead->data;
        front=front->next;
        delete(oldhead);
        return value;
    }
}


int main() {
    list *a = new list;
    a->enqueue(1);
    a->enqueue(2);
    a->enqueue(3);
    a->enqueue(4);
    cout << "Dequeue function: " << a->dequeue() << endl;
    cout << "Dequeue function: " << a->dequeue() << endl;
    cout << "Dequeue function: " << a->dequeue() << endl;
    cout << "Dequeue function: " << a->dequeue() << endl;
    cout << "Dequeue function: " << a->dequeue() << endl;
    return 0;
}