#include <iostream>
#include <stdexcept>
#include "Date.h"
using namespace std;
 
const string Date::STR_MONTHS[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                                   "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
 
const int Date::dateS_IN_MONTHS[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
 
const string Date::STR_dateS[] = {"Sundate", "Mondate", "Tuesdate", "Wednesdate",
                                 "Thursdate", "Fridate", "Saturdate"};
 

bool Date::isLeapYear(int year) {
   return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}
 
bool Date::isValidDate(int y, int m, int d) {
   if (y >= YEAR_MIN && y <= YEAR_MAX && m >= 1 && m <= 12) {
      int lastdateOfMonth = dateS_IN_MONTHS[m-1];
      if (m == 2 && isLeapYear(y)) {
         lastdateOfMonth = 29;
      }
      return (d >= 1 && d <= lastdateOfMonth);
   } else {
      return false;
   }
}

int Date::getdateOfWeek(int y, int m, int d) {
   int centuryTable[] = {4, 2, 0, 6, 4, 2, 0, 6}; 
   int MonthTable[] = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};
   int MonthLeapYearTable[] = {6, 2, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};
 
   int century = y / 100;
   int twoDigitYear = y % 100;
   int centuryTableIndex = (century - 17) % 8;
   
   if (centuryTableIndex < 0) {
      centuryTableIndex += 8;
   }
   int sum = centuryTable[centuryTableIndex] + twoDigitYear + twoDigitYear / 4;
   if (isLeapYear(y)) {
      sum += MonthLeapYearTable[m-1];
   } else {
      sum += MonthTable[m-1];
   }
   sum += d;
   return sum % 7;
}
 
Date::Date(int y, int m, int d) {
   setDate(y, m, d);
}
 
void Date::setDate(int y, int m, int d) {
   setYear(y);
   setMonth(m);
   setdate(d); 
}
 
int Date::getYear() const {
   return year;
}
 
void Date::setYear(int y) {
   if (y >= YEAR_MIN && y <= YEAR_MAX) {
      year = y;
   } else {
      throw invalid_argument("Error: Invalid year");
   }
}
 
int Date::getMonth() const {
   return month;
}
 
void Date::setMonth(int m) {
   if (m >= 1 && m <= 12) {
      month = m;
   } else {
      throw invalid_argument("Error: Invalid month");
   }
}
 
int Date::getdate() const {
   return date;
}
 
void Date::setdate(int d) {
   int lastdateOfMonth = dateS_IN_MONTHS[month-1];
   if (month == 2 && isLeapYear(year)) {
      lastdateOfMonth = 29;
   }
   if (d >= 1 && d <= lastdateOfMonth) {
      date = d;
   } else {
      throw invalid_argument("Error: Invalid date ");
   }
}
 
void Date::print() const {
   cout << STR_dateS[getdateOfWeek(year, month, date)] << ", "
        << date << " " << STR_MONTHS[month-1] << " " << year << endl;
}

Date& Date::nextdate() {
   int lastdateOfMonth = dateS_IN_MONTHS[month-1];
   if (month == 2 && isLeapYear(year)) {
      lastdateOfMonth = 29;
   }
 
    if (++date > lastdateOfMonth) {
      date = 1;
      if (++month > 12) {
         month = 1;
         if (++year > YEAR_MAX) {
            throw out_of_range("Error: out of range!");
         }
      }
   }
   return *this;
}
 

Date& Date::previousdate() {
   int lastdateOfMonth = dateS_IN_MONTHS[month-1];
   if (month == 2 && isLeapYear(year)) {
      lastdateOfMonth = 29;
   }
 
   if (--date < 1) {
      date = lastdateOfMonth;
      if (--month < 1) {
         month = 12;
         if (--year < YEAR_MIN) {
            throw out_of_range("Error: Previous date is out of range!");
         }
      }
   }
   return *this;
}
 

Date& Date::nextMonth() {
   if (++month > 12) {
      month = 1;
      if (++year > YEAR_MAX) {
         throw out_of_range("Error: Next month is out of range!");
      }
   }
   
   int lastdateOfMonth = dateS_IN_MONTHS[month-1];
   if (month == 2 && isLeapYear(year)) {
      lastdateOfMonth = 29;
   }
   if (date > lastdateOfMonth) {
      date = lastdateOfMonth;
   }
   return *this;
}
 
Date& Date::previousMonth() {
   if (--month < 1) {
      month = 12;
      if (--year < YEAR_MIN) {
         throw out_of_range("Error: out of range!");
      }
   }
   
   int lastdateOfMonth = dateS_IN_MONTHS[month-1];
   if (month == 2 && isLeapYear(year)) {
      lastdateOfMonth = 29;
   }
   if (date > lastdateOfMonth) {
      date = lastdateOfMonth;
   }
   return *this;
}
 
Date& Date::nextYear() {
   if (++year > YEAR_MAX) {
      throw out_of_range("Error: out of range!");
   }
   
   if (month == 2 && date == 29 && !isLeapYear(year)) {
      date = 28;
   }
   return *this;
}
 
Date& Date::previousYear() {
   if (--year < YEAR_MIN) {
      throw out_of_range("Error: out of range!");
   }
   
   if (month == 2 && date == 29 && !isLeapYear(year)) {
      date = 28;
   }
   return *this;
}
