// Purpose: Test the Utilities library.
//
//import DateTime;
#include <iostream>
using namespace std;
#include "DateTimeFormats.h"
using namespace Utilities;
int main()
{
	
cout << "Month: " << DateTimeFormats::PartialDate(DateTimeFormats::DatePart::Month) << endl;
cout << "Day: " << DateTimeFormats::PartialDate(DateTimeFormats::DatePart::Day) << endl;
cout << "Year: " << DateTimeFormats::PartialDate(DateTimeFormats::DatePart::Year) << endl;
cout << "Day of Month: " << DateTimeFormats::PartialDate(DateTimeFormats::DatePart::DayOfMonth) << endl;
cout << "Time Now: " << DateTimeFormats::TimeNow(DateTimeFormats::Format::Short, DateTimeFormats::TimeFormat::TwelveHour) << endl;	
cout << "Date Now: " << DateTimeFormats::DateNow(DateTimeFormats::Format::Short, DateTimeFormats::DateSeperators::Slash) << endl;
return 0;
}

