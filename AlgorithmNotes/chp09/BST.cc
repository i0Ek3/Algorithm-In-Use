// 
// BST.cc
// @ianpasm(kno30826@gmail.com)
// 2018-04-16 08:45:25
//
//
// @ BST =  binary search tree
// 
//
//
#include <cstdio> 

const int maxn = 110;

struct node {
    int data;
    node* lchild;
    node* rchild;
}Node[maxn];


//search
void search(node* root, int x)
{
    if (root == NULL)
    {
        printf("search failed!\n");
        return;
    }
    if (x == root->data)
    {
        printf("%d\n", root->data);
    }
    else if(x < root->data)
    {
        search(root->lchild, x);
    }
    else
    {
        search(root->rchild, x);
    }
}


//insert
//int index = 0;
//int newNode(int v)
//{
//    Node[index].data = v;
//    Node[index].lchild = NULL;
//    Node[index].rchild = NULL;
//    return index++;
//}


void insert(node* &root, int x)
{
    if (root == NULL)
    {
        //root = newNode(x); 
        node* root = new node;
        return;
    }
    if (x == root->data)
    {
        return;
    }
    else if(x < root->data)
    {
        insert(root->lchild, x);
    }
    else
    {
        insert(root->rchild, x);
    }
}


//create
node* create(int data[], int n)
{
    node* root = NULL;
    for (int i = 0; i < n; i++)
    {
        insert(root, data[i]);
    }
    return root;
}




//delete
node* findMax(node* root)
{
    while(root->lchild != NULL)
    {
        root = root->rchild;
    }
    return root;
}

node* findMin(node* root)
{
    while(root->lchild != NULL)
    {
        root = root->lchild;
    }
    return root;
}

void deleteNode(node* &root, int x) //dont forget &
{
    if (root == NULL)
    {
        return;
    }
    if (root->data == x)
    {
        if (root->lchild == NULL && root->rchild == NULL)
        {
            root = NULL; //
        }
        else if (root->lchild != NULL) //find precursor
        {
            node* pre = findMax(root->lchild);
            root->data = pre->data; //use pre cover root
            deleteNode(root->lchild, pre->data);
        }
        else //(root->rchild != NULL)   //find next
        {
            node* next = findMin(root->rchild);
            root->data = next->data;
            deleteNode(root->rchild, next->data);
        }
    }
    else if(x < root->data) //delete node from lchild
    {
        deleteNode(root->lchild, x);
    }
    else  //delete node from rchild
    {
        deleteNode(root->rchild, x);
    }
}


int main()
{
    
    return 0;
}


