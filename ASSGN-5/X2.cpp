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
node* Reverse(node* &head,int n){
    node* curr = head;
    node* prev = nullptr;
    node* next;

    for (int i = 0; i < n; i++)
    {
        next  = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head->next = next;
    return prev;
}
void ReverseN(node* &head,int n){
    node* temp = head;
    int count{};
    node* temp2;

    while(temp!=nullptr){
        count++;
        temp = temp->next;
    }
    int i = 0;
    while ( i != count/n)
   {
        i++;
        
        if(i==1){
            temp = head;
            head = Reverse(head,n);
            
        }
        else{
            temp2 = temp->next;
            temp->next = Reverse(temp->next,n);
            temp = temp2;
        }
        
   }
   return;
    
}


void print(node *head){
    while (head!=nullptr)
    {
        std::cout<<head->data<<" ";
        head = head->next;
    }
    
}
int main(){
    node* head1;
    head1 = new node(1);
    head1->next=new node(2);
    head1->next->next=new node(3);
    head1->next->next->next=new node(4);
    head1->next->next->next->next=new node(5);

    ReverseN(head1,2);
    print(head1);

}