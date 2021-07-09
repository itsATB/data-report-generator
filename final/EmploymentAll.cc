#include "ReportGenerator.h"

EmploymentAll::EmploymentAll(string s) : ReportGenerator(s)
{ }

EmploymentAll::~EmploymentAll()
{ }

void EmploymentAll::execute(string& outStr){
    stringstream ss;
    vector<float> proportions;
    long int totalE=0, totalG=0;

    //Get and calculate proportions for each region
    for(int i=0; i<allRegions.size(); i++){
        float prop;
        //cout<<"i: "<<i<<endl;
        for(int j=0; j<allRegions[i]->getSize(); j++){
            //cout<<"j: "<<j<<endl;
            //allRegions[i]->print();
            totalG+=allRegions[i][0][j]->getNumGrads();
            totalE+=allRegions[i][0][j]->getNumEmployed();
        }
        //Calculate, round, push to vector
        prop = ( (float)totalE/(float)totalG ) *100;
        prop = (int)(prop*1000 + .5);
        proportions.push_back( (float)prop /1000 );
    }

    //Send proportions to outString
    ss<<"Region    |    Proportion       "<<endl;
    for(int i=0; i<allRegions.size(); i++)
        ss<< allRegions[i]->getProperty() <<"        |       "<< proportions[i] <<"%       |"<<endl;
    
    outStr  = ss.str();
}
