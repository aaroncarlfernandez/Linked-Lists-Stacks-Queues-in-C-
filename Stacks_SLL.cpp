#include <iostream>
using namespace std;
//Stacks using Linked Lists
//Mapua University
struct node {
    int data;
    node *next;
};
class list
{
private:
    node *top;
public:
    list() { top=NULL; }
    int peek();
    bool isEmpty();
    void push(int new_data);
    int pop();
};
bool list::isEmpty() {
    return (top==NULL);
}
int list::peek() {
    if (!isEmpty()) {
        int value = top->data;
        return value;
    } else {
        cout << "Stack is empty!!" << endl;
        exit(1);
    }
}
void list::push(int new_data) {
    node *temp = new node;
    temp->data=new_data;
    temp->next=top;
    top=temp;
}
int list::pop() {
    if (!isEmpty()) {
        int value=top->data;
        node *oldtop = top;
        top=top->next;
        delete oldtop;
        return value;
    } else {
        cout << "You cannot pop an empty stack!" << endl;
        exit(1);
    }
}
int main() {
    list *a = new list;
    a->push(1);
    a->push(2);
    a->push(3);
    a->push(4);
    cout << "Peek function: " << a->peek() << endl;
    cout << "Pop: " << a->pop() << endl;
    cout << "Peek function: " << a->peek() << endl;
    return 0;
}