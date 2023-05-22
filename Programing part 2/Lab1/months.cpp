#include <iostream>

//An Enumeration for Presenting the Months of the Year
//Create an enumeration to represent the months of the year. 
//Implement and demonstrate overloaded operators ++ so -- that after
// December there is January and before January there is December.

enum Months {
    January,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December,
};

Months operator++(Months& mon)
{
    if (mon == December)
    {
        mon = January;
    }
    else
    {
        mon = static_cast<Months>(mon + 1);
    }
    return mon;
}

Months operator++(Months& mon, int)
{
    Months oldMon = mon;
    operator++(mon);
    return oldMon;
}

Months operator--(Months& mon)
{
    if (mon == January)
    {
        mon = December;
    }
    else
    {
        mon = static_cast<Months>(mon - 1);
    }
    return mon;
}

Months operator--(Months& mon, int)
{
    Months oldMon = mon;
    operator--(mon);
    return oldMon;
}


// Getting the names of the days of the week
const char* getName(Months mon)
{
    switch (mon)
    {
        case January: 
            return "January";
        case February:
            return "February";
        case March:
            return "March";
        case April:
            return "April";
        case May:
            return "May";
        case June:
            return "June";
        case July:
            return "July";
        case August:
            return "August";
        case September:
            return "September";
        case October:
            return "October";
        case November:
            return "November";
        case December:
            return "December";
        
            
        default:
            return "default";
    }
}

int main()
{
    std::cout << "++ overload exemple:" << "\n";
    for (Months d = November; d != October; d++)
    {
        std::cout << getName(d) << "\n";
    }
    std::cout << "\n -- overload exemple:" << "\n";
    for (Months d = October; d != November; d--)
    {
        std::cout << getName(d) << "\n";
    }

    return 0;
}