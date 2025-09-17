#include <iostream>

struct node
{
    int data;
    node* next = nullptr;
};

node *headnode = nullptr;
void add(int x){
    node *temp = new node;
    temp->data = x;

    temp->next = headnode;
    headnode = temp;
}
void addEnd(int x){
    if(headnode==nullptr){
        add(x);
        return;
    }
    node *temp = new node;
    temp->data = x;

    node* demo = headnode;
    while(1){
        if(demo->next == nullptr){
            demo->next = temp;
            return;
        }
        demo = demo->next;
    }
}
void add(int x,int p){
    node* temp = new node();
    temp->data = x;
    
    if(p==1){
        temp->next = headnode;
        headnode = temp;
        return;
    }

    node* n = headnode;
    for (int i = 0; i < p-2; i++)
    {
        n = n->next;
    }
    temp->next = n->next;
    n->next = temp;  
}
void remove(){
    node *temp = headnode;
    headnode = headnode->next;
    delete temp;
}
void removeEnd(){
    node *temp = headnode;
    node *demo{nullptr};
    if(temp->next ==nullptr){
        remove();
        return;
    }
    while (temp->next!=nullptr)
    {
        demo = temp;
        temp = temp->next;
    }
    demo->next = nullptr;
    delete temp;
}
void remove(int n){
    node *temp = headnode;
    node *demo{nullptr};
    if(temp->data == n){
        remove();
        return;
    }
    while(temp!=nullptr){
        if(temp->data == n)
            break;
        demo = temp;
        temp = temp->next;
    }
    if(temp == nullptr){
        std::cout<<"Not found"<<std::endl;
        return;}
    demo->next = temp->next;
    delete temp;
}
void search(int n){
    node *temp = headnode;
    int pos{1};
    while(temp!=nullptr){
        if(temp->data == n)
            break;
        temp = temp->next;
        pos = pos+1;
    }
    if(temp == nullptr){
        std::cout<<"Not found"<<std::endl;
        return;}
    std::cout<<"Node value "<<n<<" found at position "<<pos<<std::endl;
}
void print(){
    node *temp = headnode;

    while(temp!=nullptr){
        std::cout<<temp->data<<" ";
        temp = temp->next;
    }
    std::cout<<"\n";
}

int main(){
    add(5);
    add(6);
    add(7);

    add(2,2);
    add(3,4);
    addEnd(5);
    print();

   // remove(3);
   // print();

   // search(5);

    return 0;
}