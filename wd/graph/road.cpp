#include <cstdio>
#define N 1000

int Tree[N];

int findRoot(int x) { //路径压缩
        if (Tree[x] == -1) {
                return x;
        } else {
                int tmp = findRoot(Tree[x]);
                Tree[x] = tmp;
                return tmp;
        }
}

int main()
{
        int n, m;
        while (scanf("%d%d", &n, &m) != EOF && n != 0) { //输入
                scanf("%d", &m);
                for (int i = 1; i <= n; i++) {
                        Tree[i] = -1;
                }
                while (m-- != 0) { //读入边
                        int a, b;
                        scanf("%d%d", &a, &b);
                        a = findRoot(a);
                        b = findRoot(b);
                        if (a != b) {
                                Tree[a] = b; //合并
                        }
                }
                int ans = 0;
                for (int i = 1; i <= n; i++) {
                        if (Tree[i] == -1) {
                                ans++;
                        }
                }
                printf("%d\n", ans - 1);
        }
        return 0;
}

