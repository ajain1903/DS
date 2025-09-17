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
void count(int key){
    int count{};
    while(headnode->data==key){
        node *demo = headnode;
        headnode = headnode->next;
        delete demo;
        count = count + 1;
        }
        node *temp = headnode;
        node *demo = headnode;

        while(temp!=nullptr){
            if(temp->data == key){
                count = count+1;
                demo->next = temp->next;
                node *d = temp;
                temp = demo->next;
                delete d;

                continue;
            }
            demo = temp;
            temp = temp->next;
            
        }
        print();
    }
    int main(){
        add(1);
        add(2);
        add(1);
        add(2);
        add(1);
        add(3);
        add(1);  

        print();
        count(1);

        return 0;
    }
