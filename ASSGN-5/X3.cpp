#include <iostream>

struct node{
    int data{};
    node *next{nullptr};
};

node *headnode{nullptr};
void add(int x){
    node* temp = new node();
    temp->data = x;
    

    temp->next = headnode;
    headnode = temp;
}

void CheckCycle(){
    node* slow = headnode;
    node* fast = headnode->next;

    while(slow!=fast){
        if(!slow || !fast){
            std::cout<<"cycle not found";
            return;}
        slow = slow->next;
        fast = fast->next->next;
    }
    std::cout<<"Cycle Found";
    return;

}
int main(){
    node* temp = nullptr;
    add(5);
    add(6);
    add(7);
    CheckCycle();
    return 0;
}