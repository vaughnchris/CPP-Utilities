#ifndef TESTDATETIME_H
#define TESTDATETIME_H
#include "DateTimeFormats.h"
using namespace std;
void TestDateTime()
{
	cout << "Month: " << Utilities::DateTimeFormats::PartialDate(Utilities::DateTimeFormats::DatePart::Month) << endl;
	cout << "Day: " << Utilities::DateTimeFormats::PartialDate(Utilities::DateTimeFormats::DatePart::Day) << endl;
	cout << "Year: " << Utilities::DateTimeFormats::PartialDate(Utilities::DateTimeFormats::DatePart::Year) << endl;
	cout << "Day of Month: " << Utilities::DateTimeFormats::PartialDate(Utilities::DateTimeFormats::DatePart::DayOfMonth) << endl;
	cout << "Time Now: " << Utilities::DateTimeFormats::TimeNow(Utilities::DateTimeFormats::Format::Short, Utilities::DateTimeFormats::TimeFormat::TwelveHour) << endl;
	cout << "Date Now: " << Utilities::DateTimeFormats::DateNow(Utilities::DateTimeFormats::Format::Short, Utilities::DateTimeFormats::DateSeperators::Slash) << endl;
	cout << "The day of the year on 12/13/2020 is day: " << Utilities::DateTimeFormats::DayOfYear(12, 13, 2020) << endl;
	cout << "The day today is day: " << Utilities::DateTimeFormats::DayOfYear() << endl;
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
		Utilities::DateTimeFormats::DateTimeDiff(now, newNow,
			Utilities::DateTimeFormats::PeriodUnits::Days) << endl;
	cout << "Date Difference (Weeks): " <<
		Utilities::DateTimeFormats::DateTimeDiffByPeriod(now, newNow,
			Utilities::DateTimeFormats::PeriodUnits::Weeks) << endl;
	cout << "Date Difference (Months): " <<
		Utilities::DateTimeFormats::DateTimeDiffByPeriod(now, newNow,
			Utilities::DateTimeFormats::PeriodUnits::Months) << endl;
	cout << "Date Difference (Years): " <<
		Utilities::DateTimeFormats::DateTimeDiffByPeriod(now, newNow,
			Utilities::DateTimeFormats::PeriodUnits::Years) << endl;
	cout << "Date Difference (Hours): " <<
		Utilities::DateTimeFormats::DateTimeDiffByPeriod(now, newNow,
			Utilities::DateTimeFormats::PeriodUnits::Hours) << endl;
	cout << "Date Difference (Minutes): " <<
		Utilities::DateTimeFormats::DateTimeDiffByPeriod(now, newNow,
			Utilities::DateTimeFormats::PeriodUnits::Minutes) << endl;
	cout << "Date Difference (Seconds): " <<
		Utilities::DateTimeFormats::DateTimeDiffByPeriod(now, newNow,
			Utilities::DateTimeFormats::PeriodUnits::Seconds) << endl;
	cout << "DAy of the week for 2020-11-13: " <<
		Utilities::DateTimeFormats::DayOfWeek(12, 13, 2020) << endl;
}
#endif
