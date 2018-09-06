//calling sort() in C++, then customized your own cmp()

#include <cstdio>
#include <cstring>
#include <algorithm>

struct E {
    char name[101];
    int age;
    int score;

    // use operator
    bool operator < (const E &b) const {
        if (score != b.score) {
            return score < b.score;
        }
        int temp = strcmp(name, b.name);
        if (temp != 0) {
            return temp < 0; 
        } else {
            return age < b.age;
        }
    }
}buf[1000];


// use struct
bool cmp(E a, E b) { 
    if (a.score != b.score) {
        return a.score < b.score;
    }
    int temp = strcmp(a.name, b.name);
    if (temp != 0) {
        return temp < 0;
    } else {
        return a.age < b.age;
    }
}


int main()
{
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%s%d%d", buf[i].name, &buf[i].age, &buf[i].score);
        }

        std::sort(buf, buf + n, cmp);

        for (int i = 0; i < n; i++) {
            printf("%s->%d->%d\n", buf[i].name, buf[i].age, buf[i].score);
        }
    }

    return 0;
}

