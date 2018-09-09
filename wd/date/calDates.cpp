#include <cstdio>
#include <cstring>
#include <algorithm>

// yeap confirmation
# define ISYEAP(x) x % 100 != 0 && x % 4 == 0 || x % 400 == 0 ? 1: 0

// limitation
int buf[10000][13][32];

// day of month 
int dayOfMonth[13][2] = {
    0,0,31,31,28,29,31,31,30,30,31,31,30,30,31,31,31,31,30,30,31,31,30,30,31,31
};

// name of month
char nameOfMonth[13][5] = {
    "", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" 
};

// name of week
char nameOfWeek[7][5] = {
    "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
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

void datesCalculate() {
    
    int d1, m1, y1, d2, m2 ,y2;
    printf("Please input date(s) like this: 20180809 20110201: \n");
    while (scanf("%4d%2d%2d", &y1, &m1, &d1) != EOF) {
        scanf("%4d%2d%2d", &y2, &m2, &d2);
        printf("The differ of your input is: %d\n", abs(buf[y1][m1][d1] - buf[y2][m2][d2]) + 1);
    }
}

int main()
{
    //datesCalculate();
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

    // weekName
    int d, m, y;
    char s[5];
    printf("Please input date(s) like this: 2001 Oct 1: \n");
    while (scanf("%d%s%d", &y, s, &d) != EOF) {
        for (int m = 1; m < 13; m++) {
            if (strcmp(s, nameOfMonth[m]) == 0) {
                break;
            }
        }
        int days = buf[y][m][d] - buf[2018][9][9]; 
        days += 1;
        printf("The date of your input is: ");
        puts(nameOfWeek[(days % 7 + 7) % 7]);
        //fixme
        printf("And today is %dth day of this year!", abs(buf[y][m][d] - buf[y][1][1]) + 1);
    }

    return 0;
}

