#ifndef CONTROL_H
#define CONTROL_H
#include <iostream>
#include <string>
using namespace std;

#include "ReportGenerator.h"
#include "View.h"

/*
Class:    Control
Purpose:  contains large list of data records used to calculate statistical
            reports on recorded data

Member function:  constructor
   Side effects:  initializes ReportGenerator's records

Member function:  destructor
   Side effects:  calls Report Generator's destructor

Member function:  launch
        Purpose:  begins program
*/

class Control
{
  public:
    Control();
    void initReoprts();
    void show();
    void freeReports();
    void initMembers();
    void initRatings();
    void launch();
  private:
    vector<ReportGenerator*> reports;
    vector<string> names;
    View view;
};

#endif
