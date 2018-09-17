#include <cstdio>
#include <stack>
using std::stack;

#define N 110

stack<int> si;
char str[N], ans[N];

int main()
{
    while (scanf("%s", str) != EOF) {
        int i;
        for (i = 0; str[i] != 0; i++) {
            if (str[i] == '(') {
                si.push(i);
                ans[i] = ' ';
            } else if (str[i] == ')') {
                if (si.empty() == false) {
                    si.pop();
                    ans[i] = ' ';
                } else {
                    ans[i] = '?';
                } 
            } else {
                ans[i] = ' ';
            }
        }
        while (!si.empty()) {
            ans[si.top()] = '$';
            si.pop();
        }
        ans[i] = 0;
        puts(str);
        puts(ans);
    }
  
    return 0;
}

