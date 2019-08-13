#ifndef DATE_H
#define DATE_H
 
#include <string>
using namespace std;
 
class Date {
private:
   int year;    
   int month;   
   int date;     
   const static string STR_MONTHS[];
   const static string STR_DAYS[];
   const static int DAYS_IN_MONTHS[];
   const static int YEAR_MIN = 1000;
   const static int YEAR_MAX = 9999;
 
public:
   static bool isLeapYear(int y);
   static bool isValidDate(int y, int m, int d);
   static int getDayOfWeek(int y, int m, int d);
 
   Date(int y, int m, int d);
   void setDate(int y, int m, int d);
   int getYear() const;
   int getMonth() const;
   int getDate() const;
   void setYear(int y);
   void setMonth(int m);
   void setDate(int d);
   void print() const;
 
   Date & nextDate();
   Date & previousDate();
   Date & nextMonth();
   Date & previousMonth();
   Date & nextYear();
   Date & previousYear();
};
 
#endif
