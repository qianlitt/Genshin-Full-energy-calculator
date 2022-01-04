//输入剩余体力，计算何时满体力

#include<stdio.h>
#include<time.h>

#include"time.h"
#include"function.h"

const int unit = 8;     //回复一点体力所需时间，单位：分钟
const int full = 160;   //160满体力

int main() {
    int remainder, nowEnergy, subEnergy, needTime;
    struct Time nowTime;

/***TODO: 1.无限循环，输入bye退出
    while (1) {
        if (quit())
        {
            break;
        }
*/
    getTime(&nowTime);
    printf("now: %d-%d-%d %d:%d:%d\n", nowTime.year, nowTime.month, nowTime.day,\
        nowTime.hour, nowTime.min, nowTime.sec);

    inputEnergy(&nowEnergy);
    subEnergy = full - nowEnergy;
    needTime = subEnergy * unit;

    solution(&nowTime, needTime);
    printf("full: %d-%d-%d %d:%d:%d", nowTime.year, nowTime.month, nowTime.day,\
        nowTime.hour, nowTime.min, nowTime.sec);

    getchar();
    getchar();

    return 0;
}

void inputEnergy(int *energy) {
    printf("please enter the energy: ");
    scanf("%d", energy);
}

void getTime(struct Time *now) {
    time_t timep;
    struct tm *p;

    time(&timep);

    p = gmtime(&timep);
    p = localtime(&timep);

    //TODO: 最好使用结构体指针 Finish
    now->year = 1900+p->tm_year;
    now->month = 1+p->tm_mon;
    now->day = p->tm_mday;
    now->hour = p->tm_hour;
    now->min = p->tm_min;
    now->sec = p->tm_sec;
}

void solution(struct Time *now, int need) {
    if (need < 60)
    {
        now->min += need;
    } else {
        int h = (now->min + need) / 60;
        now->min += need - 60 * h;
        now->hour += h;
        if (now->hour >= 24)
        {
            now->hour -= 24;
            now->day += 1;
        }
    }
}