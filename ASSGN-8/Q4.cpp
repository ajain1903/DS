#include <iostream>
#include <vector>
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
void inorder(node *root,std::vector<int> &order){
    if(root ==nullptr)return;
    inorder(root->left,order);
    order.push_back(root->data);
    inorder(root->right,order);
    
}
bool check(){
    std::vector<int> order;
    inorder(headnode,order);

    for (int i = 1; i < order.size(); i++)
    {
        if(order[i-1]>order[i])
            return false;
    }
    return true;
}
int main(){
    insert(5);
    insert(2);
    insert(1);
    insert(3);
    insert(4);
    
    if(check())std::cout<<"True";
    else std::cout<<"False";

    return 0;
}