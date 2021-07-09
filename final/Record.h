#ifndef RECORD_H
#define RECORD_H
#include <string>
#include <iostream>
using namespace std;

class Record
{
public:
    Record(int, string, string, string, int, int);
    ~Record();
    int getYear();
    string getRegion();
    string getDegree();
    string getGender();
    int getNumGrads();
    int getNumEmployed();
    void print();
private:
    int year;
    string region;
    string degree;
    string gender;
    int numEmployed;
    int numGrads;

};

#endif
