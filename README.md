## AlgorithmNotes

Personal learning Algorithm notes.Instances with .cpp or .c files.

## Instances

### 符号常量
```C
#define PI 3.14
const double PI = 3.14; //recommand
```
### 多点测试
```C
while(scanf("%d",&n) != EOF){...} //while...EOF，即题目没有给出结束条件

while(scanf("%d%d",&a,&b),a||b){...} //while...break，即题目给出结束条件

scanf("%d".&T);
while(T--){...} //while(T--)，即给定测试数据的组数，需要用变量T来存储，并在开始时读入
```


### BubbleSort
```C
#include <stdio.h>

int main()
{
    int a[10] = {3,1,4,5,2};
    for(int i = 1; i <= 4; i++)
    {
        for(int j = 0; j <= 5 - i; j++)
        {
            if(a[i] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    for(i = 0; i < 5; i++)
    {
        printf("%d\n",a[i]);
    }
    return 0;
}   
```

# 注意
* scanf对%s不需要&
    ```C
    scanf("%d-%lld-%f-%lf-%c-%s\n",&n,&n,&fl,&db,&c,str);
    ```
* char型数组整个输入不需要&
* scanf的%c格式是可以读入空格跟换行的
* 用getchar()/putchar()输入、输出单个字符
* 用gets()和puts()输入、输出一行字符串
* float和double更推荐double
* 在浮点数的比较中利用eps(=10^-8)来修正误差
    ```C
    const double eps = 1e-8;
    ```

