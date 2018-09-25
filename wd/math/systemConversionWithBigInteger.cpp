#include <cstdio>
#include <cstring>
#define max 100
#define N 10000
char str[N], ans[N];

struct Big { //高精度整数结构体
        int digit[max];
        int size;

        void init() { //初始化
                for (int i = 0; i < max; i++) {
                        digit[i] = 0;
                }
                size = 0;
        }

        void set(int x) { //用普通整数初始化高精度整数
                init();
                do { //对小整数4位为一个单位分解一次存入digit数组
                        digit[size++] = x % N;
                        x /= N;
                } while (x != 0);
        }

        void output() { //输出
                for (int i = size - 1; i >= 0; i--) {
                        if (i != size - 1) {
                                printf("%04d", digit[i]);
                        } else {
                                printf("%d", digit[i]);
                        }
                }
                printf("\n");
        }

        Big operator * (int x) const { //高精度整数与普通整数的乘积
                Big ret;
                ret.init();
                int carry = 0; //进位
                for (int i = 0; i < size; i++) {
                        int tmp = x * digit[i] + carry; //用小整数x乘以当前位数字再加上来自低位的进位
                        carry = tmp / N; //计算进位
                        tmp %= N; //去除进位部分
                        ret.digit[ret.size++] = tmp; //保存该位数字
                }
                if (carry != 0) { //若最高位有进位
                        ret.digit[ret.size++] = carry; //保存该进位
                }
                return ret;
        }

        Big operator + (const Big &A) const { //高精度整数之间的加法运算
                Big ret;
                ret.init();
                int carry = 0;
                for (int i = 0; i < A.size || i < size; i++) {
                        int tmp = A.digit[i] + digit[i] + carry;
                        carry = tmp / N;
                        tmp %= N;
                        ret.digit[ret.size++] = tmp;
                }
                if (carry != 0) {
                        ret.digit[ret.size++] = carry;
                }
                return ret;
        }

        Big operator / (int x) const { //高精度整数与普通整数的除法
                Big ret;
                ret.init();
                int re = 0; //余数
                for (int i = size - 1; i >= 0; i--) { //从最高位到最低位依次完成计算
                        int t = (re * N + digit[i]) / x;
                        int r = (re * N + digit[i]) % x;
                        ret.digit[i] = t; //保存本位的值
                        re = r; //保存到本位为止的余数
                } 
                ret.size = 0;
                for (int i = 0; i < max; i++) {
                        if (digit[i] != 0) { //若存在非0位，确定最高的非0位，作为最高有效位
                                ret.size = i;
                        }
                }
                ret.size++;
                return ret;
        }

        int operator % (int x) const { //高精度整数对普通整数求余
                int re = 0;
                for (int i = size - 1; i >= 0; i--) {
                        int t = (re * N + digit[i]) / x;
                        int r = (re * N + digit[i]) % x;
                        re = r;
                }
                return re;
        }
}a, b, c;

int main()
{
        int n, m;
        while (scanf("%d%d", &m, &n) != EOF) {
                scanf("%s", str); //输入m进制数
                int L = strlen(str);
                a.set(0); //用来保存转换称10进制的m进制数
                b.set(1); //m -> 10的权重
                for (int i = L - 1; i >= 0; i--) { //由低位到高位转化m进制数至相应的10进制数
                        int t;
                        if (str[i] >= '0' && str[i] <= '9') {
                                t = str[i] - '0';
                        } else {
                                t = str[i] - 'A' + 10;
                        }
                        a = a + b * t; //累加当前数字乘当前位权重的积
                        b = b * m; //计算下一位权重
                }

                int size = 0; //转换为n进制数后的字符个数
                do { //对转换后的10进制数求其n进制数后的字符个数
                        int t = a % n; //求余
                        if (t >= 10) { 
                                ans[size++] = t + 'a' - 10;
                        } else {
                                ans[size++] = t + '0'; //确定当前位字符
                        }
                        a = a / n; //求商
                } while (a.digit[0] != 0 || a.size != 1);

                for (int i = size - 1; i >= 0; i--) {
                        printf("%c", ans[i]);
                }
                printf("\n");
        }
        return 0;
}

