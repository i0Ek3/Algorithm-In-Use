## AlgorithmNotes

Personal learning Algorithm notes.Instances with .cpp or .c files.

## Instances

|---|-------|----|
|---|-------|----|

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

### 注意
* scanf对%s不需要&
    ```C
    scanf("%d-%lld-%f-%lf-%c-%s\n",&n,&n,&fl,&db,&c,str);
    ```
* char型数组整个输入不需要&
* scanf的%c格式是可以读入空格跟换行的
* 用getchar()/putchar()输入、输出单个字符
* 用gets()和puts()输入、输出一行字符串
* float和double更推荐double
* const对象必须初始化
* 在浮点数的比较中利用eps(=10^-8)来修正误差
    ```C
    const double eps = 1e-8;
    ```
* 以下代码仅仅声明了i而没有定义它 
    ```C
    extern int i;
    ```
* nan表示Not a Number,inf表示Infinity无限大
* 尽量避免如下写法
    ```C
    int* p1,p2;
    ```
  应该写成这样
    ```C
    int *p1,p2; 
    int *p1;
    int *p2;
    ```
* 面对较为复杂的指针或引用的声明语句时,可考虑从右往左阅读
* 在使用递增或递减中我们尽量使用前置递增和前置递减来避免不必要的错误


### Updates
>2017
>>11-25:Whatever I'll update...add something you can find in the file code/,actually my pc boomed!!!.<br>
>>11-26:Add next chapter learning--sort algorithm!<br>
>>11-27:Add insertSort algorithm.<br>
>>12-05:Add sort contents.<br>
>>[More...](https://github.com/i0Ek3/AlgorithmNotes/blob/master/updates.md)
