#include <iostream>
#include <queue>
#include <vector>
struct node{
    int data{};
    node *left{nullptr},*right{nullptr};
};
node* headnode{nullptr};
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
std::vector<int> rightView(node* root) {
    std::vector<int> ans;
    if (!root) return ans;
    std::queue<node*> q;

    q.push(root);
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; ++i) {
            node* cur = q.front(); q.pop();
            // if it's the last node in this level, add to answer
            if (i == sz - 1) ans.push_back(cur->data);
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
    }
    return ans;
}
int main(){
    insert(5);
    insert(6);
    insert(4);
    insert(8);
    insert(7);

}