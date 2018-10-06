#include <cstdio>
#include <map>
#include <string>
using std::map;
using std::string;
#define N 100

map<string, int> M;
int inDegree[2000];

int main()
{
        int n;
        while (scanf("%d", &n) != EOF && n != 0) {
                for (int i = 0; i < 2*n; i++) {
                        inDegree[i] = 0;
                }
                M.clear();
                int idx = 0;
                for (int i = 0; i < n; i++) {
                        char s1[N], s2[N];
                        scanf("%s%s", s1, s2);
                        string a = s1, b = s2;
                        int idxa, idxb;
                        if (M.find(a) == M.end()) {
                                idxa = idx;
                                M[a] = idx++;
                        } else {
                                idxa = M[a];
                        }
                        if (M.find(b) == M.end()) {
                                idxb = idx;
                                M[b] = idx++;
                        } else {
                                idxb = M[b];
                        }
                        inDegree[idxb]++;
                }
                int ans = 0;
                for (int i = 0; i < idx; i++) {
                        if (inDegree[i] == 0) {
                                ans++;
                        }
                }
                puts(ans == 1 ? "Yes" : "No");
        }
        
        return 0;
}

