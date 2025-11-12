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

node *buildTree(std::vector<int> inorder,std::vector<int> postorder)
{
    int size = postorder.size()-1;
    return RbuildTree(inorder,0,size,postorder,0,size);
}

node *RbuildTree(std::vector<int> &inorder,int is,int ie,std::vector<int> &postorder,int ps,int pe)
{
    if(is>ie || ps>pe)
        return;

    node *temp = new node();
    temp->data=postorder[pe];

    int inroot=search(postorder[pe],inorder);
    int numleft=inroot-is;

    temp->left = RbuildTree(inorder,is,inroot,postorder,ps,ps+numleft-1);
    temp->right= RbuildTree(inorder,inroot+1,ie,postorder,ps+numleft,pe-1);

    return temp;

}