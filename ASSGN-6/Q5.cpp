#include <iostream>
struct node
{
    int data{};
    node *next{nullptr};

    node(){    }

    node(int data){
        this->data = data;
    }
};

void CLL(node* headnode){
    node *temp = headnode->next;
    while(temp!=headnode){
        if(temp ==nullptr){
            std::cout<<"False";
            return;
        }
        temp=temp->next;
    }
    std::cout<<"True";
}
int main(){

    node* head1;
    head1 = new node(1);
    head1->next=new node(2);
    head1->next->next=new node(3);
    head1->next->next->next=new node(4);
    head1->next->next->next->next=new node(5);

    head1->next->next->next->next->next=head1;
    CLL(head1);

    return 0;
}