// 
// binaryTree.cc
// @ianpasm(kno30826@gmail.com)
// 2018-04-07 09:20:17
// 
//
//
//
#include <cstdio>

 
// binary link
struct node {
    typename data; //data field
    node* lchild;  //point to node which belong lchild
    node* rchild; 
    //node* NULL;   //if not exist child please point to NULL
};

//before build binary tree there is no root node, so
node* root = NULL;

//operation function
//01 renew node
node* newNode(int v)
{
    node* Node = new node; //apply address space for node type
    Node->data = v; //node weight v
    Node->lchild = Node->rchild = NULL; //no child under initial status
    return Node; //return node address
}

//02 search node
void search(node* root, int x, int newdata)
{
    if (root == NULL)
    {
        return;
    }
    if (root->data == x)
    {
        root->data = newdata;
    }
    search(root->lchild, x, newdata);
    search(root->rchild, x, newdata);
}

//03 insert node
//if not use reference & cannot insert succeed
void insert(node* &root, int x)
{
    //null tree direct insert node
    if (root == NULL)
    {
        root = newNode(x);
        return;
    }
    if () // need insert node on lchild
    {
        insert(root->lchild, x);
    }
    else
    {
        insert(root->rchild, x);
    }
}

//04 create binary tree
node* Create(int data[], int n)
{
    node* root = NULL; //new null node: root
    for (int i = 0; i < n; i++) //loop insert node to root
    {
        insert(root, data[i]);
    }
    return root; 
}

int main()
{

    return 0;
}


