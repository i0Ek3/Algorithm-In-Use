// DAG ---> Topology

#include <cstdio>
#include <queue>
#include <vector>
#define N 500

std::vector<int> edge[N];
std::queue<int> Q;

int main()
{
        int inDegree[N];
        int n, m;
        while (scanf("%d%d", &n, &m) != EOF) {
                if (n == 0 && m == 0) {
                        break;
                }
                for (int i = 0; i < n; i++) {
                        inDegree[i] = 0;
                        edge[i].clear();
                }
                while (m--) {
                        int a, b; //a line which point to b from a
                        scanf("%d%d", &a, &b);
                        inDegree[b]++;
                        edge[a].push_back(b); //add b to a's link 
                }
                while (Q.empty() == false) {
                        Q.pop();
                }
                for (int i = 0; i < n; i++) {
                        if (inDegree[i] == 0) {
                                Q.push(i);
                        }
                }
                int count = 0;
                while (Q.empty() == false) {
                        int currentNode = Q.front();
                        Q.pop();
                        count++;
                        for (int i = 0; i < edge[currentNode].size(); i++) {
                                inDegree[edge[currentNode][i]]--;
                                if (inDegree[edge[currentNode][i]] == 0) {
                                        Q.push(edge[currentNode][i]);
                                }
                        }
                }
                if (count == n) {
                        puts("YES\n");
                } else {
                        puts("NO\n");
                }

        }
        
        return 0;
}

