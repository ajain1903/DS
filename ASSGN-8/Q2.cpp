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
auto max(node *temp){
    
    while(temp->right!=nullptr){
        temp = temp->right;
    }
    std::cout<<"Max element: "<<temp->data<<std::endl;
    return temp;
}
auto min(node* temp){
    
    while(temp->left!=nullptr){
        temp = temp->left;
    }
    std::cout<<"Min element: "<<temp->data<<std::endl;
    return temp;
}
node* inorderSuccessor(node* root, node* target) {
    if (!root || !target) return nullptr;
    
    // Case 1: right subtree exists
    if (target->right)
        return min(target->right);

    // Case 2: no right subtree → find lowest ancestor greater than target
    node* succ = nullptr;
    node* curr = root;
    while (curr) {
        if (target->data < curr->data) {
            succ = curr;        // possible successor
            curr = curr->left;
        } else if (target->data > curr->data) {
            curr = curr->right;
        } else break; 
    }
    return succ;
}


node* inorderPredecessor(node* root, node* target) {
    if (!root || !target) return nullptr;
    
    // Case 1: left subtree exists
    if (target->left)
        return max(target->left);

    // Case 2: no left subtree → find lowest ancestor smaller than target
    node* pred = nullptr;
    node* curr = root;
    while (curr) {
        if (target->data > curr->data) {
            pred = curr;        
            curr = curr->right;
        } else if (target->data < curr->data) {
            curr = curr->left;
        } else break; 
    }
    return pred;
}