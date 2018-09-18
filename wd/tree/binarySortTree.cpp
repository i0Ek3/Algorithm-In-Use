#include <cstdio>
#include <cstring>
#define N 110

int allocated;

struct Node {
        Node *lchild;
        Node *rchild;
        int c;
}Tree[N];

Node *create() {
        Tree[allocated].lchild = Tree[allocated].rchild = NULL;
        return &Tree[allocated++];
}

void preOrder(Node *T) {
        printf("%d", T->c);
        if (T->lchild != NULL) {
                preOrder(T->lchild);
        }
        if (T->rchild != NULL) {
                preOrder(T->rchild);
        }
}

void inOrder(Node *T) {
        if (T->lchild != NULL) {
                inOrder(T->lchild);
        }
        printf("%d", T->c);
        if (T->rchild != NULL) {
                inOrder(T->rchild);
        }
}

void postOrder(Node *T) {
        if (T->lchild != NULL) {
                postOrder(T->lchild);
        }
        if (T->rchild != NULL) {
                postOrder(T->rchild);
        }
        printf("%d", T->c);
}

Node *insert(Node *T, int x) {
        if (T == NULL) {
                T = create();
                T->c = x;
                return T;
        } else if (x < T->c) {
                T->lchild = insert(T->lchild, x);
        } else if (x > T->c) {
                T->rchild = insert(T->rchild, x);
        }
        return T;
}

int main()
{   
        int n;
        while (scanf("%d", &n) != EOF) {
                allocated = 0;
                Node *T = NULL;
                for (int i = 0; i < n; i++) {
                        int x;
                        scanf("%d", &x);
                        T = insert(T, x);
                }
                preOrder(T);
                printf("\n");
                inOrder(T);
                printf("\n");
                postOrder(T);
                printf("\n");
        }
        return 0;
}

