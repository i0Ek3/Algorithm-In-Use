// 
// AVL.cc
// @ianpasm(kno30826@gmail.com)
// 2018-04-18 10:21:17
// 
//
// @AVL Tree
//
//
//
//
#include <cstdio>
#include <algorithm>
using namespace std;

struct node {
    int v, height, data;
    node* rchild, lchild;
};

node* newNode(int v)
{
    node* Node = new node;
    Node->v = v;
    Node->height = 1;
    Node->lchild = Node->rchild = NULL;
    return Node;
}

//fetch height of current tree
int getHeight(node* root)
{
    if (root == NULL)
    {
        return 0;
    }
    return root->height;
}

int getBlanceFactor(node* root)
{
    return getHeight(root->lchild) - getHeight(root->rchild);
}

void updateHeight(node* root)
{
    root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

//search
void search(node* root, int x)
{
    if (root == NULL)
    {
        printf("search failed.\n");
        return 0;
    }
    if (x == root->data)
    {
        printf("%d\n", root->x);
    }
    else if (x < root->data)
    {
        search(root->lchild, x);
    }
    else
    {
        search(root->rchild, x);
    }
}



