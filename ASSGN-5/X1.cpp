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
void difference(node* &h1,node* &h2,int d){
    node *temp1 = h1,*temp2 = h2;
    for (int i = 0; i < d; i++)
    {
        temp1 = temp1->next;
    }
    while (temp1!=nullptr && temp2!=nullptr)
    {
        if(temp1==temp2){
            std::cout<<"intersection at "<<temp1->data;
            return;
        }
        temp1=temp1->next;
        temp2 = temp2->next;
    }
    return;
    
}
void intersection(node* &h1,node* &h2){
    int c1{0},c2{0};
    node *temp1 = h1,*temp2 = h2;
    while (temp1!=nullptr && temp2!=nullptr)
    {
        c1++;c2++;
        temp1=temp1->next;
        temp2 = temp2->next;
    }
    while (temp1!=nullptr )
    {
        c1++;
        temp1=temp1->next;
        
    }
    while (temp2!=nullptr)
    {
        c2++;
        temp2 = temp2->next;
    }

    if(c1>=c2){
        difference(h1,h2,c1-c2);
    }
    else 
        difference(h2,h1,c2-c1);

    
    return;
}

int main(){
    node* head1;
    head1 = new node(4);
    head1->next=new node(1);
    head1->next->next=new node(8);
    head1->next->next->next=new node(5);


    node* head2;
    head2= new node(5);
    head2->next=new node(6);
    head2->next->next=new node(1);
    head2->next->next->next=head1->next->next;

    intersection(head1,head2);

}