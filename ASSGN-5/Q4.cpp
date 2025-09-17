#include <iostream>

struct node{
    int data{};
    node *next{nullptr};
};

node *headnode{nullptr};

void add(int x){
    node *temp = new node;
    temp->data = x;

    if(headnode==nullptr){
        headnode = temp;
        return;
    }

    node* demo = headnode;
    while(1){
        if(demo->next == nullptr){
            demo->next = temp;
            return;
        }
        demo = demo->next;
    }
}
void print(){
    node *temp = headnode;

    while(temp!=nullptr){
        std::cout<<temp->data<<" ";
        temp = temp->next;
    }
    std::cout<<"\n";
}
void reverse(){
    node *temp = headnode;
    node *demo = temp;
    node *prev = nullptr;

    while(temp!= nullptr){
        demo =temp;
        temp = temp->next;
        demo->next = prev;
        prev = demo;        
    }
    headnode = demo;
}
int main(){
    add(1);
    add(2);
    add(3);
    add(4);
    add(5);
    print();

    reverse();
    print();
}