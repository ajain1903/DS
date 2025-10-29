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

void print(node* headnode){
    node *temp = headnode;

    do
    {
        std::cout<<temp->data<<" ";
        temp= temp->next;
    } while (temp!=headnode);
    std::cout<<temp->data<<std::endl;
    
}

int main(){

    node* head1;
    head1 = new node(1);
    head1->next=new node(2);
    head1->next->next=new node(3);
    head1->next->next->next=new node(4);
    head1->next->next->next->next=new node(5);

    head1->next->next->next->next->next=head1;
    print(head1);

    return 0;
}