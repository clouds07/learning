// typedefs example
#include <iostream>
#include <vector>

using namespace std;

typedef enum days {
    MON, TUE, WED, THU, FRY, SAT, SUN
} days;


ostream& operator<< (ostream& ostr, days  day)
{
    switch (day)
    {
        case MON:   return ostr << "MON"; break;
        case TUE:   return ostr << "TUE"; break;
        case WED:   return ostr << "WED"; break;
        case THU:   return ostr << "THU"; break;
        case FRY:   return ostr << "FRY"; break;
        case SAT:   return ostr << "SAT"; break;
        case SUN:   return ostr << "SUN"; break;
        
        default:
            break;
    }

    return ostr;
}

inline days operator++ (days day)
{
    return static_cast<days>((static_cast<int>(day) + 1) % 7);
}

int main(void)
{
    days myDay {TUE};

    cout << "Today is " << myDay << endl;

    cout << "Tomorrow will be " << ++myDay << endl;
}
