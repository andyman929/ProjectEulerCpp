/*
You are given the following information, but you may prefer to do some research for yourself.

1 Jan 1900 was a Monday.
Thirty days has September,
April, June and November.
All the rest have thirty-one,
Saving February alone,
Which has twenty-eight, rain or shine.
And on leap years, twenty-nine.
A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
*/

#include <vector>
#include "pch.h"

using namespace std;

void ProjectsObjDLL1::Project19Calc()
{
    // start on tuesday 1st Jan 1901
    int day = 1;
    int sundays = 0;

    for (int yr = 1901; yr < 2001; yr++)
    {
        for (int mth = 0; mth < 12; mth++)
        {
            int daysAdded = Project19DaysInMonth(mth, yr);
            day = (day + daysAdded) % 7;
            if (day == 6)
                sundays += 1;
        }
    }

    cout << "Sundays on the first of the month: " << sundays << "\n";
}

int ProjectsObjDLL1::Project19DaysInMonth(int month, int year)
{
    switch (month) 
    {
    case 0:
    case 2:
    case 4:
    case 6:
    case 7:
    case 9:
    case 11:
        return 31;
    case 3:
    case 5:
    case 8:
    case 10:
        return 30;
    default:
        if (year % 4 == 0)
        {
            if (year % 100 == 0 && year % 400 != 0)
            {
                return 28;
            }
            return 29;
        }
        return 28;
    }
}