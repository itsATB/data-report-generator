#include "Record.h"

Record::Record(int y, string r, string d, string g, int ne, int ng) :
    year(y), region(r), degree(d), gender(g), numEmployed(ne), numGrads(ng)
{ }

Record::~Record(){
    //cout << "--record dtor -- "<<endl;
}

int Record::getYear(){  return year;}
string Record::getRegion(){  return region; }
string Record::getDegree(){  return degree; }
string Record::getGender(){  return gender; }
int Record::getNumGrads(){  return numGrads;    }
int Record::getNumEmployed(){  return numEmployed;  }

void Record::print(){
    cout<<" "<<year<<" "<<region<<" "<<degree<<" "<<gender<<" "
      <<numEmployed<<" "<<numGrads<<endl;
}
