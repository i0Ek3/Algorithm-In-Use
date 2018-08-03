// 
// link.cpp
// @ianpasm(kno30826@gmail.com)
// 2018-03-26 09:37:49
// 
 
#include <cstdio>
#include <cstdlib>

struct node {
    int data;
    node* next;
};

node* create_link(int array[])
{
    node *p, *pre, *head;
    head = new node;
    head->next = NULL;
    pre = head;
    for (int i = 0; i < 5; i++)
    {
        p = new node;
        p->data = array[i];
        p->next = NULL;
        pre->next = p;
        pre = p;
    }
    return head;
}

int find_x(node* head, int x)
{
    int count = 0;
    node* p = head->next;
    while (p != NULL)
    {
        if (p->data == x)
        {
            count++;
        }
        p = p->next;
    }
    return count;
}

void insert_x(node* head, int pos, int x)
{
    node* p = head;
    for (int i = 0; i < pos - 1; i++)
    {
        p = p->next;
    }
    node* q = new node;
    q->data = x;
    q->next = p->next;
    p->next = q;
}

void delete_x(node* head, int x)
{
    node* p = head->next;
    node* pre = head;
    while (p != NULL)
    {
        if (p->data == x)
        {
            pre->next = p->next;
            delete(p);
            p = pre->next;
        }
        else
        {
            pre = p;
            p = p->next;
        }
    }
}


int main()
{
    int array[5] = {5, 3, 6, 1, 2};
    node* L = create_link(array);
    L = L->next;
    while (L != NULL)
    {
        printf("%d->", L->data);
        L = L->next;
    }
    find_x(L, 3);
    insert_x(L, 3, 3);
    delete_x(L, 4);
    
    return 0;
}
