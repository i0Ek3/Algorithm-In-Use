#include <cstdio>
#include <algorithm>
#define N 101
int Tree[N];

int findRoot(int x) {
        if (Tree[x] == -1) {
                return x;
        } else {
                int tmp = findRoot(Tree[x]);
                Tree[x] = tmp;
                return tmp;
        }
}

struct Edge {
        int a, b;
        int cost;
        bool operator < (const Edge &A) const {
                return cost < A.cost;
        }
}edge[5000];

int main()
{
        int n;
        while (scanf("%d", &n) != EOF && n != 0) {
                int l = n * (n - 1) / 2;
                for (int i = 1; i <= l; i++) {
                        scanf("%d%d%d", &edge[i].a, &edge[i].b, &edge[i].cost);
                }
                std::sort(edge + 1, edge + 1 + l);
                for (int i = 1; i <= n; i++) {
                        Tree[i] = -1;
                }
                int ans = 0;
                for (int i = 1; i <= l; i++) {
                        int a = findRoot(edge[i].a);
                        int b = findRoot(edge[i].b);
                        if (a != b) {
                                Tree[a] = b;
                                ans += edge[i].cost;
                        }
                }
                printf("%d\n", ans);
        }

        return 0;
}

