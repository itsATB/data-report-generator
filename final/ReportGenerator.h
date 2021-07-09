#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <iterator>
#include <iomanip>
using namespace std;

#include "Record.h"
#include "Property.h"

/*
Class:    ReportGenerator
Purpose:  contains large list of data records used to calculate statistical
            reports on recorded data

Member function:  constructor
   Side effects:  initializes ReportGenerator with given name

Member function:  destructor
   Side effects:  deallocates all data records that were loaded in.
                  contians a bool data member to check if they have been freed already
                  so they aren't freed again

Member function:  loadRecords
        Purpose:  allocates and fills primary collection of records

Member function:  loadPartials
        Purpose:  adds record pointers from primeary collection to
                    corresponding partial collection

Member function:  execute
        Purpose:  calculates data for report, formats and outputs data as string
            out:  string printed by view obj
*/
class ReportGenerator
{
public:
    ReportGenerator(string);
    ~ReportGenerator();
    static void loadRecords(); 
    static void loadPartials();
    virtual void execute(string&) = 0;
    string getName();
    //void printRecords();

protected:
    string name;
    static bool isfreed;
    static vector<Record*> recordsPrime;
    static vector< Property<int>* > allYears;
    static vector< Property<string>* > allRegions;
    static vector< Property<string>* > allDegrees;
    static vector< Property<string>* > allGenders;
};


/*
Classes:    ReportGenerator derived objects
Purpose:  specialized polymorphic objects for formatting different reports

Member function:  execute
        Purpose:  polymorphic function to format different reports
*/


class EmploymentAll : public ReportGenerator
{
public:
    EmploymentAll(string);
    ~EmploymentAll();
    void execute(string&);
};

class EmploymentFemale : public ReportGenerator
{
public:
    EmploymentFemale(string);
    ~EmploymentFemale();
    void execute(string&);
    void calcTop(vector<float>&, vector<string>&);
    void calcBottom(vector<float>&, vector<string>&);
};

class EmploymentYear : public ReportGenerator
{
public:
    EmploymentYear(string);
    ~EmploymentYear();
    void execute(string&);
    void calcYear(int, int, vector<float>&);
};

class DegreeReport : public ReportGenerator
{
public:
    DegreeReport(string);
    ~DegreeReport();
    void execute(string&);
    void calcHighest(string, int, vector<string>&);
};

class AverageReport : public ReportGenerator
{
public:
    AverageReport(string);
    ~AverageReport();
    void execute(string&);
    void calcAvg(string, int, int, vector<float>&);
};

#endif
