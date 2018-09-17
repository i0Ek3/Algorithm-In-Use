// Given inorder and preorder seq, please output postorder seq.

#include <cstdio>
#include <cstring>

#define N 50
int allocated; 
char pre[N], in[N]; // to save preorder and inorder result 

struct Node {
        Node *lchild;
        Node *rchild;
        char c;
}Tree[N];

Node *create() {
        Tree[allocated].lchild = Tree[allocated].rchild = NULL;
        return &Tree[allocated++];
}

void postOrder(Node *T) {
        if (T->lchild != NULL) {
                postOrder(T->lchild);
        }
        if (T->rchild != NULL) {
                postOrder(T->rchild);
        }
        printf("%c", T->c);
}

Node *build(int s1, int e1, int s2, int e2) {
        Node* ret = create();
        ret->c = pre[s1];
        int index;
        for (int i = s2; i <= e2; i++) {
                if (in[i] == pre[s1]) {
                        index = i;
                        break;
                }
        }
        if (index != s2) {
                ret->lchild = build(s1+1, s1+(index-s2), s2, index-1);
        }
        if (index != e2) {
                ret->rchild = build(s1+(index-s2)+1, e1, index+1, e2);
        }
        return ret;
}

int main()
{
        while (scanf("%s", pre) != EOF) {
                scanf("%s", in);
                allocated = 0;
                int left1 = strlen(pre);
                int left2 = strlen(in);
                Node *T = build(0, left1-1, 0, left2-1);
                postOrder(T);
                printf("\n");
        }
        
        return 0;
}

