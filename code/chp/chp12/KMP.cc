// 
// KMP.cc
// @ianpasm(kno30826@gmail.com)
// 2018-07-13 16:14:11
// 
// @KMP Problem
//

#include <cstdio>
#include <iostream>

const int maxn = 1000;
int next[maxn];

void getNext(char s[], int len)
{
    int j = -1;
    next[0] = -1;
    for (int i = 1; i < len; i++) {
        while (j != -1 && s[i] != s[i + 1]) {
            j = next[j];
        }
        if (s[i] == s[i + 1]) {
            j++;
        }
        next[i] = j;
    }
}

int KMP(char text[], char pattern[]) //substring and pattern string 
{
    int n = strlen(text), m = strlen(pattern);
    getNext(pattern, m); //calculate the next array for pattern
    int j = -1, ans = 0; //ans indicate times of substring apperance
    for (int i = 0; i < n; i++) {
        while (j != -1 && text[i] != pattern[j + 1]) {
            j = next[j];
        }
        if (text[i] == pattern[j + 1]) {
            j++;
        }
        if (j == m -1) {
            ans++;
            j = next[j];
        }
    }
    return ans;
    printf("%d\n", ans);
}

int main()
{
    char text[] = 'abc';
    char pattern[] = 'asbacabc';
    KMP(text, pattern);

    return 0;
}




