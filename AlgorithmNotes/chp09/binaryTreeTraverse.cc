// 
// binaryTreeTraverse.cc
// @ianpasm(kno30826@gmail.com)
// 2018-04-09 09:45:26
// 
// 
//
//
//
#include <cstdio>
#include <queue>
using namespace std;

 
//1 PreOrder
void PreOrder(node* root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d\n", root->data);
    PreOrder(root->lchild);
    PreOrder(root->rchild);
}


//2 InOrder
void InOrder(node* root)
{
    if (root == NULL)
    {
        return;
    }
    InOrder(root->lchild);
    printf("%d\n", root->data);
    InOrder(root->rchild);
}


//3 PostOrder
void PostOrder(node* root)
{
    if (root == NULL)
    {
        return;
    }
    PostOrder(root->lchild);
    PostOrder(root->rchild);
    printf("%d\n", root->data);
}


//4 LayerOrder
struct node {
    int data;
    int layer;
    node* lchild;
    node* rchild;
};

void LayerOrder(node* root)
{
    queue<node*> q;
    root->layer = 1;
    q.push(root);
    while (!q.empty())
    {
        node* now = q.front();
        q.pop();
        printf("%d\n", now->data);
        if (now->lchild != NULL)
        {
            now->lchild->layer = now->layer + 1;
            q.push(now->lchild);
        }
        if (now->rchild != NULL)
        {
            now->rchild->layer = now->layer + 1;
            q.push(now->rchild);
        }
    }
}

//**
//Given PreOrder and InOrder to rebuild this binarytree.
node* rebuild(int preL, int preR, int inL, int inR)
{
    if (preL > preR)
    {
        return NULL;
    }

    node* root = new node;
    root->data = pre[preL];
    
    int k;
    for (k = inL; k <= inR; k++) 
    {
        if (in[k] == pre[preL])
        {
            break;
        }
    }
    int numLeft = k - inL; //lchild numbers

    root->lchild = rebuild(preL + 1, preL + numLeft, inL, k - 1); //lchild
    root->rchild = rebuild(preL + numLeft + 1, preR, k + 1, inR); //rchild

    return root;
}

int main()
{

    return 0;
}

