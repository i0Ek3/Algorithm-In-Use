// 
// pat_a1043.cc
// @ianpasm(kno30826@gmail.com)
// 2018-04-16 09:32:35
//
// 
// @Is it a BST?
//  Given a sequence of integer keys, if the tree is the preorder traverse or the mirror image of a BST.Please output the tree's postorder traverse.
//
//
 
#include <cstdio>
#include <vector>
using std::vector;

struct node {
    int data;
    node* left;
    node* right;
};

void insert(node* &root, int data)
{
    //judge null
    if (root == NULL)
    {
        root = new node;
        root->data = data;
        root->left = root->right = NULL;
        return;
    }

    //insert
    if (data < root->data)
    {
        insert(root->left, data);
    }
    else
    {
        insert(root->right, data);
    }
}

//common tree preOrder traverse
void preOrder(node* root, vector<int>&vi)
{
    if (root == NULL)
    {
        return;
    }
    vi.push_back(root->data);

    //common preOrder, left first then right
    preOrder(root->left, vi);
    preOrder(root->right, vi);
}

//mirror tree preOrder traverse
void mirrorPreOrder(node* root, vector<int>&vi)
{
    if (root == NULL)
    {
        return;
    }
    vi.push_back(root->data);

    //different with preOrder, right first then left
    mirrorPreOrder(root->right, vi);
    mirrorPreOrder(root->left, vi);
}

//common tree postOrder traverse
void postOrder(node* root, vector<int>&vi)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left, vi);
    postOrder(root->right, vi);
    vi.push_back(root->data);
}

//mirror tree postOrder traverse
void mirrorPostOrder(node* root, vector<int>&vi)
{
    if (root == NULL)
    {
        return;
    }
    mirrorPostOrder(root->right, vi);
    mirrorPostOrder(root->left, vi);
    vi.push_back(root->data);
}

//origin is intial sequence
vector<int> origin, pre, preMirror, post, postMirror;

int main()
{
    int n, data;
    node* root = NULL; //defination for head node
    scanf("%d", &n); //input the nodes numbers

    //build a origin tree
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        origin.push_back(data);
        insert(root, data);
    }    

    preOrder(root, pre);
    mirrorPreOrder(root, preMirror);
    postOrder(root, post);
    mirrorPostOrder(root, postMirror);

    if (origin == pre) //initial sequence equals common tree traverse preOrder
    {
        printf("YES\n");
        //output postOrder traverse sequence sperate by one space
        for (int i = 0; i < post.size(); i++)
        {
            printf("%d", post[i]);
            if (i < post.size() - 1)
            {
                printf(" ");
            }
        }
    }
    else if(origin == preMirror) //initial sequence equals mirror tree preOrder
    {
        printf("YES\n");
        //output mirrorPostOrder traverse sequence sperate by one space
        for (int i = 0; i < postMirror.size(); i++)
        {
            printf("%d", postMirror[i]);
            if (i < postMirror.size() - 1)
            {
                printf(" ");
            }
        }
    }
    else // not mirror tree
    {
        printf("NO\n");
    }

    return 0;
}


