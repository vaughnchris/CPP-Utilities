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
        tm now = getTimeStruct();
        string hours, minutes, seconds, timeString;
        hours = to_string(now.tm_hour % 12);

        minutes = to_string(now.tm_min);
        if (minutes.length() == 1)
            minutes = "0" + minutes;

        if (format == Format::Short)
        {
            if (timeFormat == TimeFormat::TwelveHour) {
                if (hours == "0")
                    hours = "12";
                timeString = hours + ":" + minutes + " " +
                    (now.tm_hour > 12 ? "PM" : "AM");
            }
            else
                timeString = hours + ":" +
                minutes;
        }
        else
        {
            if (timeFormat == TimeFormat::TwelveHour) {
                hours = to_string(now.tm_hour % 12);
                if (hours == "0")
                    hours = "12";
                minutes = to_string(now.tm_min);
                if (minutes.length() == 1)
                    minutes = "0" + minutes;
                timeString = hours + ":" + minutes +
                    ":" + to_string(now.tm_sec) + " " +
                    (now.tm_hour > 12 ? "PM" : "AM");
            }
            else {
                seconds = to_string(now.tm_sec);
                if (seconds.length() == 1)
                    seconds = "0" + seconds;
                timeString = hours + ":" +
                    minutes + ":" +
                    seconds;
            }
        }
        return timeString;
    }
    string DateTimeFormats::DateNow(Format format, 
        DateSeperators seperator) {
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
            tm now = getTimeStruct();
            month = to_string(now.tm_mon + 1);
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
    tm DateTimeFormats::getTimeStruct() {
		time_t t;
		time(&t);
		struct tm now;
		localtime_s(&now, &t);
		return now;
	}
    string DateTimeFormats::DateTimeNow(Format format, 
        DateSeperators seperator,
        Format timeLengthFormat, TimeFormat timeFormat) {
        string dateTimeString = DateNow(format, seperator) + " " +
            TimeNow(timeLengthFormat, timeFormat);
        return dateTimeString;
    }
    string DateTimeFormats::PartialDate(DatePart part) {
        string dateString = NowToString();
        string datePart;
        tm now;
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
            case DatePart::WeekOfYear:
                now = getTimeStruct();
                datePart = to_string(now.tm_yday / 7);
                break;
            case DatePart::DayOfYear:
                now = getTimeStruct();
                datePart = to_string(now.tm_yday);
                break;
        }
        return datePart;
    }
    int DateTimeFormats::DateTimeDiffByPeriod(tm first, tm second,
        PeriodUnits units)
    {
        int years = second.tm_year - first.tm_year;
		int months = second.tm_mon - first.tm_mon;
		int days = second.tm_mday - first.tm_mday;
		int hours = second.tm_hour - first.tm_hour;
		int minutes = second.tm_min - first.tm_min;
		int seconds = second.tm_sec - first.tm_sec;
		int totalSeconds = (years * 31536000) + (months * 2592000) + (days * 86400) + (hours * 3600) + (minutes * 60) + seconds;
        switch (units)
        {
            case PeriodUnits::Seconds:
				return totalSeconds;
            case PeriodUnits::Minutes:
                return totalSeconds / 60;
            case PeriodUnits::Hours:
                return totalSeconds / 3600;
			case PeriodUnits::Days:
				return totalSeconds / 86400;
			case PeriodUnits::Weeks:
				return totalSeconds / 604800;
			case PeriodUnits::Months:
				return totalSeconds / 2592000;
			case PeriodUnits::Years:
				return totalSeconds / 31536000;
        }


    }
    string DateTimeFormats::DayOfWeek(const int day, const int month, const int year)
    {
        tm date;
        date.tm_year = year - 1900;
        date.tm_mon = month - 1;
        date.tm_mday = day;
        time_t t;
        localtime_s(&date, &t);
        return getDayFullString(to_string(date.tm_wday));
    }
    void DateTimeFormats::ParseDate(string& day, 
        string& dayOfMonth,string& month, string& year, 
        string& time) {
		string dateString = NowToString();
		day = getDayFullString(dateString.substr(0, 3));
        dayOfMonth = dateString.substr(8, 2);
        if(dayOfMonth[0] == ' ')
			dayOfMonth[0] = '0';
		month = getMonthFullString(dateString.substr(4, 3));
		year = dateString.substr(20, 4);
        time = dateString.substr(11, 8);
	}
    string DateTimeFormats::DateTimeDiff(tm first, tm second, 
        PeriodUnits precision)
    {
        string difference;
        int years = second.tm_year - first.tm_year;
        int months = second.tm_mon - first.tm_mon;
        int days = second.tm_mday - first.tm_mday;
        int hours = second.tm_hour - first.tm_hour;
        int minutes = second.tm_min - first.tm_min;
        int seconds = second.tm_sec - first.tm_sec;
        int totalSeconds = (years * 31536000) + (months * 2592000) +
            (days * 86400) + (hours * 3600) + (minutes * 60) + seconds;
        int remainingSeconds;
        years = totalSeconds / 31536000;
        remainingSeconds = totalSeconds % 31536000;
        months = remainingSeconds / 2592000;
        remainingSeconds = remainingSeconds % 2592000;
        days = remainingSeconds / 86400;
        remainingSeconds = remainingSeconds % 86400;
        hours = remainingSeconds / 3600;
        remainingSeconds = remainingSeconds % 3600;
        minutes = remainingSeconds / 60;
        seconds = remainingSeconds % 60;
        if (years != 0 && precision <= PeriodUnits::Years)
            difference += to_string(years) + " years, ";
        if (months != 0 && precision <= PeriodUnits::Months)
            difference += to_string(months) + " months, ";
        if (days != 0 && precision <= PeriodUnits::Days)
            difference += to_string(days) + " days, ";
        if (hours != 0 && precision <= PeriodUnits::Hours)
            difference += to_string(hours) + " hours, ";
        if (minutes != 0 && precision <= PeriodUnits::Minutes)
            difference += to_string(minutes) + " minutes, ";
        if (seconds != 0 && precision <= PeriodUnits::Seconds)
            difference += to_string(seconds) + " seconds, ";
        return difference;
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
