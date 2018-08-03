// 
// staticBinaryTree.cpp
// @ianpasm(kno30826@gmail.com)
// 2018-04-12 10:11:09
//
// The visit for pointer all change to array index.
//
//

// defination for node
struct node {
    typename data;
    int lchild;
    int rchild;
}Node[maxn];


//appoint statically
int index = 0;
int newNode(int v)
{
    Node[index].data = v;
    Node[index].lchild = -1;
    Node[index].rchild = -1;
    return index++;
}

//operations
void search(int root, int x, int newdata)
{
    if (root == -1)
    {
        return;
    }
    if (Node[root].data == x)
    {
        Node[root].data = newdata;
    }
    search(Node[root].lchild, x, newdata);
    search(Node[root].rchild, x, newdata);
}

void insert(int &root, int x)
{
    if (root == -1)
    {
        root = newNode(x);
        return ;
    }
    if ()
    {
        insert(Node[root].lchild,  x);
    }
    else
    {
        insert(Node[root].rchild,  x);
    }
}

int create(int data[], int n)
{
    int root = -1;
    for (int i = 0; i < n; i++)
    {
        insert(root, data[i]);
    }
    return root;
}

void PreOrder(int root)
{
    if (root == -1)
    {
        return;
    }
    printf("%d\n", Node[root].data);
    PreOrder(Node[root].lchild);
    PreOrder(Node[root].rchild);
}

void InOrder(int root)
{
    if (root == -1)
    {
        return;
    }
    InOrder(Node[root].lchild);
    printf("%d\n", Node[root].data);
    InOrder(Node[root].rchild);
}

void PostOrder(int root)
{
    if (root == -1)
    {
        return;
    }
    PostOrder(Node[root].lchild);
    PostOrder(Node[root].rchild);
    printf("%d\n", Node[root].data);
}

void LayerOrder(int root)
{
    queue<int> q;
    q.push(root);
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        printf("%d ", Node[now].data);
        if (Node[now].lchild != -1)
        {
            q.push(Node[root].lchild);
        }
        if (Node[now].rchild != -1)
        {
            q.push(Node[root].rchild);
        }
    }
}



int main()
{



    return 0;
}

