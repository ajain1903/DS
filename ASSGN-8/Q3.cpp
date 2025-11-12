#include <iostream>
#include <algorithm>
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

int maxDepth(node* root){
    if(root == nullptr) return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return 1 + std::max(leftDepth, rightDepth);
}
int main(){
    insert(5);
    insert(2);
    insert(1);
    insert(3);
    insert(4);
    inorder(headnode);

    return 0;
}