#include <cstdio>
#include <cstring>
#define N 110

int alloc;
char str1[25], str2[25]; //save preOrder and inOrder traverse results. 
int size1, size2; //save number of char in char array
char *str; //current saving str 
int *size; //current saving size 

struct Node {
        Node *lchild;
        Node *rchild;
        int c;
}Tree[N];

Node *create() {
        Tree[alloc].lchild = Tree[alloc].rchild = NULL;
        return &Tree[alloc++];
}

// Here must be have inOrder function can only deduce final seq.
void preOrder(Node *T) {
        if (T->lchild != NULL) {
                preOrder(T->lchild);
        }
        if (T->rchild != NULL) {
                preOrder(T->rchild);
        }
        str[(*size)++] = T->c + '0';
}

void inOrder(Node *T) {
        if (T->lchild != NULL) {
                inOrder(T->lchild);
        }
        str[(*size)++] = T->c + '0';
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
        str[(*size)++] = T->c + '0';
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
        char tmp[12];
        while (scanf("%d", &n) != EOF && n != 0) {
                alloc = 0;
                Node *T1 = NULL;
                scanf("%s", tmp);
                for (int i = 0; tmp[i] != 0; i++) {
                        T1 = insert(T1, tmp[i]-'0');
                }
                size1 = 0;
                str = str1;
                size = &size1;
                postOrder(T1);
                inOrder(T1);
                str1[size1] = 0;
                while (n-- != 0) {
                        scanf("%s", tmp);
                        Node *T2 = NULL;
                        for (int i = 0; tmp[i] != 0; i++) {
                                T2 = insert(T2, tmp[i] - '0');
                        }
                        size2 = 0;
                        str = str2;
                        size = &size2;
                        postOrder(T2);
                        inOrder(T2);
                        str2[size2] = 0;
                        puts(strcmp(str1, str2) == 0 ? "YES" : "NO");
                }
        }
        return 0;
}

