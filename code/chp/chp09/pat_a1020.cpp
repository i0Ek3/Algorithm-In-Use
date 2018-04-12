// 
// pat_a1020.cpp
// @ianpasm(kno30826@gmail.com)
// 2018-04-12 09:17:33
// 
//
// @Question
// Given PostOrder and InOrder please given LayerOrder.
//
// @Case
//  input: 
//      7
//      2 3 1 5 7 6 4
//      1 2 3 4 5 6 7
//  output: 
//      4 1 6 3 5 7 2
//
 
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 50;
struct node {
    int data;
    node* lchild;
    node* rchild;
};

int pre[maxn], in[maxn], post[maxn];
int n; //node numbers

node* rebuild(int postL, int postR, int inL, int inR)
{
    int k;
    if (postL > postR)
    {
        return NULL;
    }
    node* root = new node;
    root->data = post[postR];

    for (k = inL; k <= inR; k++)
    {
        if (in[k] == post[postR])
        {
            break;
        }
    }
    int numbers = k - inL;
    root->lchild = rebuild(postL, postL + numbers - 1, inL, k - 1);
    root->rchild = rebuild(postL + numbers, postR - 1, k + 1, inR);
}

int num = 0; //already output node numbers
void BFS(node* root)
{
    queue<node*> q;
    q.push(root);
    while (!q.empty())
    {
        node* now = q.front(); //take out the first element
        q.pop(); 
        printf("%d",now->data); //visit the first element
        num++;
        if (num < n)
        {
            printf(" ");
        }

        //if lchild and rchild non-null then push them into queue
        if (now->lchild != NULL)
        {
            q.push(now->lchild);
        }
        if (now->rchild != NULL)
        {
            q.push(now->rchild);
        }
    }
}


int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &post[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &in[i]);
    }
    
    node* root = rebuild(0, n - 1, 0, n - 1); //rebuild binarytree
    BFS(root); //LayerOrder traverse
    return 0;
}


