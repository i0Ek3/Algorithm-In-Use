#include <cstdio>
#include <algorithm>

// yeap confirmation
# define ISYEAP(x) x % 100 != 0 && x % 4 == 0 || x % 400 == 0 ? 1: 0

// limitation
int buf[10000][13][32];

// days of month 
int dayOfMonth[13][2] = {
    0,0,31,31,28,29,31,31,30,30,31,31,30,30,31,31,31,31,30,30,31,31,30,30,31,31
};

struct Date{
    int Day;
    int Month;
    int Year;
    void nextDay() {
        Day++;
        if (Day > dayOfMonth[Month][ISYEAP(Year)]) {
            Day = 1;
            Month++;
            if (Month > 12) {
                Month = 1;
                Year++;
            }
        }
    }
};

int main()
{
    Date tmp;
    int cnt = 0;
    tmp.Day = 1;
    tmp.Month = 1;
    tmp.Year = 0;
    while (tmp.Year != 10000) {
        
        // save differs with date 0000-01-01
        buf[tmp.Year][tmp.Month][tmp.Day] = cnt;
        tmp.nextDay();
        cnt++;
    }

    int d1, m1, y1, d2, m2 ,y2;
    while (scanf("%4d%2d%2d", &y1, &m1, &d1) != EOF) {
        scanf("%4d%2d%2d", &y2, &m2, &d2);
        printf("%d\n", abs(buf[y1][m1][d1] - buf[y2][m2][d2]) + 1);
    }

    return 0;
}

