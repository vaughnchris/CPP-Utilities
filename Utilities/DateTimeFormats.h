//
// Created by Christopher Vaughn on 3/6/24.
//

#ifndef POINTERS_DATETIMEFORMATS_H
#define POINTERS_DATETIMEFORMATS_H
#include <iostream>
#include <string>

using namespace std;
namespace Utilities {
    class DateTimeFormats {
    public:
        enum class Format {
            Short,
            Long
        };
        enum class DateSeperators {
            Slash,
            Dash,
            Dot
        };
        enum class TimeFormat {
            TwelveHour,
            TwentyFourHour
        };
        enum class DatePart {
            Day,
            Month,
            Year,
            DayOfMonth
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
    private:
        static string getTimeNow();
        static tm* getTimeStruct();
        static string getDayFullString(string day);
        static string getMonthFullString(string month);
    };

} // Utilities

#endif //POINTERS_DATETIMEFORMATS_H
