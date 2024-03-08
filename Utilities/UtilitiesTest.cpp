// Purpose: Test the Utilities library.
//
#include <iostream>
#include "SingleLinkedCircularList.h"
#include "DateTimeFormats.h"
using namespace std;
using namespace Utilities;
int main()
{
cout << "Month: " << DateTimeFormats::PartialDate(DateTimeFormats::DatePart::Month) << endl;
cout << "Day: " << DateTimeFormats::PartialDate(DateTimeFormats::DatePart::Day) << endl;
cout << "Year: " << DateTimeFormats::PartialDate(DateTimeFormats::DatePart::Year) << endl;
cout << "Day of Month: " << DateTimeFormats::PartialDate(DateTimeFormats::DatePart::DayOfMonth) << endl;
cout << "Time Now: " << DateTimeFormats::TimeNow(DateTimeFormats::Format::Short, DateTimeFormats::TimeFormat::TwelveHour) << endl;	
cout << "Date Now: " << DateTimeFormats::DateNow(DateTimeFormats::Format::Short, DateTimeFormats::DateSeperators::Slash) << endl;
tm now;
tm newNow;
now.tm_year = 2020;
now.tm_mon = 11;
now.tm_mday = 13;
now.tm_hour = 13;
now.tm_min = 0;
now.tm_sec = 0;
newNow.tm_year = 2024;
newNow.tm_mon = 7;
newNow.tm_mday = 23;
newNow.tm_hour = 12;
newNow.tm_min = 40;
newNow.tm_sec = 20;
cout << "Date Difference: " << "" << 
	DateTimeFormats::DateTimeDiff(now, newNow, 
	DateTimeFormats::PeriodUnits::Days) << endl;
cout << "Date Difference (Weeks): " << 
	DateTimeFormats::DateTimeDiffByPeriod(now, newNow, 
	DateTimeFormats::PeriodUnits::Weeks) << endl;
cout << "Date Difference (Months): " <<
	DateTimeFormats::DateTimeDiffByPeriod(now, newNow, 
	DateTimeFormats::PeriodUnits::Months) << endl;
cout << "Date Difference (Years): " <<
	DateTimeFormats::DateTimeDiffByPeriod(now, newNow, 
	DateTimeFormats::PeriodUnits::Years) << endl;
cout << "Date Difference (Hours): " <<
	DateTimeFormats::DateTimeDiffByPeriod(now, newNow, 
	DateTimeFormats::PeriodUnits::Hours) << endl;
cout << "Date Difference (Minutes): " <<
	DateTimeFormats::DateTimeDiffByPeriod(now, newNow, 
	DateTimeFormats::PeriodUnits::Minutes) << endl;
cout << "Date Difference (Seconds): " <<
	DateTimeFormats::DateTimeDiffByPeriod(now, newNow, 
	DateTimeFormats::PeriodUnits::Seconds) << endl;
cout << "DAy of the week for 2020-11-13: " << 
	DateTimeFormats::DayOfWeek(now) << endl;
cout << "Day of the week for 2024-07-23: " <<
	DateTimeFormats::DayOfWeek(newNow) << endl;
return 0;
}

