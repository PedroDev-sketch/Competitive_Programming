#include <stdio.h>

struct entrance
{
    int numEnt;
    int numDate;
};

struct date
{
    int day;
    int month;
    int year;
};

struct alumni
{
    struct entrance num;
    struct date birthday;
};

int main()
{
    struct alumni pedro;
    scanf("%d %d", &pedro.num.numEnt, &pedro.num.numDate);
    scanf("%d %d %d", &pedro.birthday.day, &pedro.birthday.month, &pedro.birthday.year);
    printf("%d.%d\n", pedro.num.numEnt, pedro.num.numDate);
    printf("%02d/%02d/%d", pedro.birthday.day, pedro.birthday.month, pedro.birthday.year);

    return 0;
}