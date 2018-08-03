// 
// stackProblem.cc
// @ianpasm(kno30826@gmail.com)
// 2018-05-31 12:24:24
//
// PAT A1057 Stack(30)
//

#include <cstdio>
#include <cstring>
#include <stack>
using std::stack;

const int maxn = 100010;
const int sqrN = 316;

stack<int> st;
int block[sqrN];
int table[maxn];

void peekMedian(int k)
{
    int idx = 0;
    int sum = 0;
    while (sum + block[idx] < k) {
        sum += block[idx++];
    } 
    int num = idx * sqrN;
    while (sum + table[num] < k) {
        sum += table[num++];
    }
    printf("%d\n", num);
}

void Push(int x)
{
    st.push(x);
    block[x / sqrN]++;
    table[x]++;
}

void Pop()
{
    int x = st.top();
    st.pop();
    block[x / sqrN]--;
    table[x]--;
    printf("%d\n", x);
}

int main()
{
    int x, query;
    char cmd[20];
    scanf("%d", &query);
    memset(block, 0, sizeof(block));
    memset(table, 0, sizeof(table));
    for (int i = 0; i < query; i++) {
        scanf("%s", cmd);
        if (strcmp(cmd, "Push") == 0) {
            scanf("%d", &x);
            Push(x);
        } else if (strcmp(cmd, "Pop") == 0) {
            if (st.empty() == true) {
                printf("Invalid\n");
            } else {
                Pop();
            }
        } else {
            if (st.empty() == true) {
                printf("Invalid\n");
            } else {
                int k = st.size();
                if (k % 2 == 1) {
                    k = (k + 1) / 2;
                } else {
                    k *= 0.5;
                }
                peekMedian(k);
            }
        }
    }
    return 0;
}
