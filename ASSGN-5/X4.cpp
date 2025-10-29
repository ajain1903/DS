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

void rotate(node* &head,int n){

    node* temp = head;
    int count;
    while(temp!=nullptr)
    {
        count++;
        if(temp->next==nullptr){
            temp->next = head;
            break;
        }
        temp = temp->next;
        
    }
    n = n%count;
    node* prev = temp;
    temp = head;
    
    for (int i = 0; i < n; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = nullptr;
    head = temp; return;
}
void print(node *head){
    while (head!=nullptr)
    {
        std::cout<<head->data<<" ";
        head = head->next;
    }
    return;
}
int main(){
    node* head1;
    head1 = new node(1);
    head1->next=new node(2);
    head1->next->next=new node(3);
    head1->next->next->next=new node(4);
    
    head1->next->next->next->next=new node(5);

    rotate(head1,4);
    print(head1);

}