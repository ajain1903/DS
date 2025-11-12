#include <iostream>
struct node{
    int data{};
    node *left{nullptr},*right{nullptr};
};
node* headnode{nullptr};
int dfs(node* root, bool isLeft) {
        if(!root) return 0;
        if(!root -> left && !root -> right) return isLeft ? root -> data : 0;
        return dfs(root -> left, true) + dfs(root -> right, false);
}
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
int main(){

}