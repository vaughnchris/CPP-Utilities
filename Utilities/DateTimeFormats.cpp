//
// Created by Christopher Vaughn on 3/6/24.
//

#include "DateTimeFormats.h"
using namespace std;
namespace Utilities {
    string DateTimeFormats::NowToString()
    {
        string timeString = getTimeNow();
        return timeString;
    }
    string DateTimeFormats::TimeNow(Format format,
        TimeFormat timeFormat) {
        tm* now = getTimeStruct();
        string hours, minutes, seconds, timeString;
        hours = to_string(now->tm_hour % 12);

        minutes = to_string(now->tm_min);
        if (minutes.length() == 1)
            minutes = "0" + minutes;

        if (format == Format::Short)
        {
            if (timeFormat == TimeFormat::TwelveHour) {
                if (hours == "0")
                    hours = "12";
                timeString = hours + ":" + minutes + " " +
                    (now->tm_hour > 12 ? "PM" : "AM");
            }
            else
                timeString = hours + ":" +
                minutes;
        }
        else
        {
            if (timeFormat == TimeFormat::TwelveHour) {
                hours = to_string(now->tm_hour % 12);
                if (hours == "0")
                    hours = "12";
                minutes = to_string(now->tm_min);
                if (minutes.length() == 1)
                    minutes = "0" + minutes;
                timeString = hours + ":" + minutes +
                    ":" + to_string(now->tm_sec) + " " +
                    (now->tm_hour > 12 ? "PM" : "AM");
            }
            else {
                seconds = to_string(now->tm_sec);
                if (seconds.length() == 1)
                    seconds = "0" + seconds;
                timeString = hours + ":" +
                    minutes + ":" +
                    seconds;
            }
        }
        return timeString;
    }
    string DateTimeFormats::DateNow(Format format, DateSeperators seperator) {
        string dayOfWeek, dayOfMonth, month, year, time, dateString;
        ParseDate(dayOfWeek,dayOfMonth, month, year, time);
     
        char seperatorChar = '/';
        if (format == Format::Short)
        {
            switch (seperator)
            {
            case DateSeperators::Slash:
                seperatorChar = '/';
                break;
            case DateSeperators::Dash:
                seperatorChar = '-';
                break;
            case DateSeperators::Dot:
                seperatorChar = '.';
                break;
            }
            tm* now = getTimeStruct();
            month = to_string(now->tm_mon + 1);
            if(month.length() == 1)
				month = "0" + month;
            dateString = month + seperatorChar +
                dayOfMonth + seperatorChar + 
                year;
        }
        else
        {
            dateString = PartialDate(DatePart::Day) + ", " +
                PartialDate(DatePart::Month) + " " +
                PartialDate(DatePart::DayOfMonth) + ", " +
                PartialDate(DatePart::Year);
        }
        return dateString;
    }
    string DateTimeFormats::getTimeNow() {
        time_t t;
        time(&t);
        struct tm now;
        localtime_s(&now, &t);
        char timeBuffer[26];
        asctime_s(timeBuffer, sizeof timeBuffer, &now);
        return timeBuffer;
	}
    tm* DateTimeFormats::getTimeStruct() {
		time_t t;
		time(&t);
		struct tm now;
		localtime_s(&now, &t);
		return &now;
	}
    string DateTimeFormats::DateTimeNow(Format format, DateSeperators seperator,
        Format timeLengthFormat, TimeFormat timeFormat) {
        string dateTimeString = DateNow(format, seperator) + " " +
            TimeNow(timeLengthFormat, timeFormat);
        return dateTimeString;
    }
    string DateTimeFormats::PartialDate(DatePart part) {
        string dateString = NowToString();
        string datePart;
        switch (part)
        {
        case DatePart::Day:
            datePart = dateString.substr(0, 3);
            datePart = getDayFullString(datePart);
            break;
        case DatePart::Month:
            datePart = dateString.substr(4, 3);
            datePart = getMonthFullString(datePart);
            break;
        case DatePart::Year:
            datePart = dateString.substr(20, 4);
            break;
        case DatePart::DayOfMonth:
            datePart = dateString.substr(8, 2);
            //if the first character is a space, replace with 0
            if (datePart[0] == ' ')
				datePart[0] = '0';
            break;
        }
        return datePart;
    }
    void DateTimeFormats::ParseDate(string& day, string& dayOfMonth,string& month, string& year, string& time) {
		string dateString = NowToString();
		day = getDayFullString(dateString.substr(0, 3));
        dayOfMonth = dateString.substr(8, 2);
        if(dayOfMonth[0] == ' ')
			dayOfMonth[0] = '0';
		month = getMonthFullString(dateString.substr(4, 3));
		year = dateString.substr(20, 4);
        time = dateString.substr(11, 8);
	}
    string DateTimeFormats::getDayFullString(string day) {
        string fullDay;
        if (day == "Sun")
            fullDay = "Sunday";
        else if (day == "Mon")
            fullDay = "Monday";
        else if (day == "Tue")
            fullDay = "Tuesday";
        else if (day == "Wed")
            fullDay = "Wednesday";
        else if (day == "Thu")
            fullDay = "Thursday";
        else if (day == "Fri")
            fullDay = "Friday";
        else if (day == "Sat")
            fullDay = "Saturday";
        return fullDay;
    }
    string DateTimeFormats::getMonthFullString(std::string month) {
        string fullMonth;
        if (month == "Jan")
            fullMonth = "January";
        else if (month == "Feb")
            fullMonth = "February";
        else if (month == "Mar")
            fullMonth = "March";
        else if (month == "Apr")
            fullMonth = "April";
        else if (month == "May")
            fullMonth = "May";
        else if (month == "Jun")
            fullMonth = "June";
        else if (month == "Jul")
            fullMonth = "July";
        else if (month == "Aug")
            fullMonth = "August";
        else if (month == "Sep")
            fullMonth = "September";
        else if (month == "Oct")
            fullMonth = "October";
        else if (month == "Nov")
            fullMonth = "November";
        else if (month == "Dec")
            fullMonth = "December";
        return fullMonth;
    }
}; // Utilities
