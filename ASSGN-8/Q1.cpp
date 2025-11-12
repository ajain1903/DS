#include <iostream>
struct node{
    int data{};
    node *left{nullptr},*right{nullptr};
};
node *headnode{nullptr};
void insert(int data){
    
    node *temp = new node;
    temp->data = data;
    if(headnode == nullptr){
        std::cout<<" data inputed: "<<temp->data<<std::endl;
        headnode = temp;
        return;
    }
    node *demo = headnode;
    while (demo!=nullptr)
    {   
        if(temp->data<demo->data){
            if(demo->left==nullptr){
                demo->left=temp;
                std::cout<<" data inputed: "<<temp->data<<std::endl;
                return;
            }
            else{
                demo = demo->left;}
        }
        else{
            if(demo->right==nullptr){
                demo->right=temp;
                std::cout<<" data inputed: "<<temp->data<<std::endl;
                return;
            }
            else{
                demo = demo->right;}
        }
    }
    
}
void inorder(node* head){
    if(head==nullptr){
        return;
    }

    inorder(head->left);
    std::cout<<head->data<<" ";
    inorder(head->right);
    return;
}
void preorder(node* head){
    if(head==nullptr){
        return;
    }
    std::cout<<head->data<<" ";
    preorder(head->left);
    preorder(head->right);
    return;
}
void postorder(node* head){
    if(head==nullptr){
        return;
    }
    postorder(head->left);
    postorder(head->right);
    std::cout<<head->data<<" ";
    return;
}
int main(){
    insert(5);
    insert(2);
    insert(1);
    insert(3);
    insert(4);
    inorder(headnode);
    std::cout<<"\n";
    postorder(headnode);
    std::cout<<"\n";
    preorder(headnode);

    return 0;
}