// 
// AVL.cc
// @ianpasm(kno30826@gmail.com)
// 2018-04-18 10:21:17
// 
//
// @AVL Tree
//  You need adjust the balance factor of tree repeatly until reached balance.
//



#include <cstdio>
#include <algorithm>
using namespace std;

struct node {
    int v, height, data;
    node* rchild;
    node* lchild;
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

int getBalanceFactor(node* root)
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
        return;
    }

    if (x == root->data)
    {
        printf("%d\n", root->data);
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

//left rotation
void LR(node* &root)
{
    node* temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void RR(node* &root)
{
    node* temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

//judge whether lost balance
void insert(node* &root, int v)
{
    if (root == NULL)
    {
        root = newNode(v);
        return;
    }

    if (v < root->v)
    {
        insert(root->lchild, v);
        updateHeight(root);
        if (getBalanceFactor(root) == 2)
        {
            if (getBalanceFactor(root->lchild) == 1)
            {
                RR(root);
            }
            else if (getBalanceFactor(root->lchild) == -1)
            {
                LR(root->lchild);
                RR(root);
            }
        }
    }
    else
    {
        insert(root->rchild, v);
        updateHeight(root);
        if (getBalanceFactor(root) == -2)
        {
            if (getBalanceFactor(root->rchild) == -1)
            {
                LR(root);
            }
            else if (getBalanceFactor(root->rchild) == 1)
            {
                RR(root->rchild);
                LR(root);
            }
        }
    }
}

node* buildTree(int data[], int n)
{
    node* root = NULL;
    for (int i = 0; i < n; i++)
    {
        insert(root, data[i]);
    }
    return root;
}


int main()
{



    return 0;
}

