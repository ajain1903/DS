#include <iostream>
#include <vector>

struct node{
    int data{};
    node *left{nullptr},*right{nullptr};
};
auto search(int data,std::vector<int> inorder)
{
    for (int i = 0; i < inorder.size(); i++)
    {
        if (data==inorder[i])
        {
            return i;
        }
    }
}

node *buildTree(std::vector<int> inorder,std::vector<int> preorder)
{
    int size = inorder.size()-1;
    return RbuildTree(inorder,0,size,preorder,0,size);
}

node *RbuildTree(std::vector<int> &inorder,int is,int ie,std::vector<int> &preorder,int ps,int pe)
{
    if(is>ie || ps>pe)
        return;
    
    node *temp = new node();
    temp->data=preorder[ps];
    
    int inroot=search(preorder[ps],inorder);
    int numleft=inroot-is;

    temp->left=RbuildTree(inorder,is,inroot-1,preorder,ps+1,ps+numleft);
    temp->right=RbuildTree(inorder,inroot+1,ie,preorder,ps+numleft+1,pe);

    return temp;
}