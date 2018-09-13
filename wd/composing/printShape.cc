#include <cstdio>


// 对于规则形状，可以容易找出其中规律，将规律程序化即可。对于不太容易看出的图形，可以考虑使用缓存数组，先将需要的内容存入缓存数组，然后再排版后输出！




int main()
{
    int h;
    while (scanf("%d", &h) != EOF) {
        int lastLineSize = h + (h - 1) * 2;
        for (int i = 1; i <= h ; i++) {
            for (int j = 1; j <= lastLineSize; j++) {
                if (j < lastLineSize - h - (i - 1) * 2 + 1) {
                    printf(" ");
                } else {
                    printf("*");
                } 
            }
            printf("\n");
        }
    }

    return 0;
}

