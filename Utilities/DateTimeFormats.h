//
// Created by Christopher Vaughn on 3/6/24.
//
#ifndef DT_FORMATS_H
#include <iostream>
#include <string>
#include <ctime>
using namespace std;
namespace Utilities {
    class DateTimeFormats {
    public:
        enum class PeriodUnits {
			Seconds,
			Minutes,
			Hours,
			Days,
			Weeks,
			Months,
			Years
		};
        enum class Format {
            Short,
            Medium,
            Long,
            Full
        };
        enum class DateSeperators {
            Slash,
            Dash,
            Dot,
            Space
        };
        enum class TimeFormat {
            TwelveHour,
            TwentyFourHour
        };
        enum class DatePart {
            Day,
            Month,
            Year,
            DayOfMonth,
            WeekOfYear,
            DayOfYear
        };
        //returns a readable string of the current time
        // composite
        static string NowToString();
        //returns a string of the current time
        //in the specified format "long/short"
        //and time format "12/24 hr"
        static string TimeNow(Format = Format::Short,
            TimeFormat = TimeFormat::TwelveHour);
        //returns a string of the current date
        //in the specified format "long/short"
        //and date seperator "slash/dash/dot"
        static string DateNow(Format = Format::Short,
            DateSeperators = DateSeperators::Slash);
        static string DateTimeNow(Format = Format::Short,
            DateSeperators = DateSeperators::Slash,
            Format timeLengthFormat = Format::Short,
            TimeFormat = TimeFormat::TwelveHour);
        //returns a string representing a partial date
        //based on the date part
        //Day, Month, Year, or DayOfMonth
        static string PartialDate(DatePart part);
        static void ParseDate(string& day, string& dayOfMonth,
            string& month, string& year, string& time);
        static string DateTimeDiff(tm first, tm second, 
            PeriodUnits precision);
        static int DateTimeDiffByPeriod(tm first, tm second, 
            			PeriodUnits precision);
        static string DayOfWeek(int day, int month, int year);
        static int DayOfYear(int day, int month, int year);
        static int DayOfYear();
    private:
        static string getTimeNow();
        static tm getTimeStruct();
        static string getDayFullString(string day);
        static string getMonthFullString(string month);
    };
} 
#endif // !DT_FORMATS_H
