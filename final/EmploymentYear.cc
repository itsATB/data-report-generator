#include "ReportGenerator.h"

EmploymentYear::EmploymentYear(string s) : ReportGenerator(s)
{ }

EmploymentYear::~EmploymentYear()
{ }

void EmploymentYear::execute(string& outStr){
    stringstream ss;
    vector<float> proportion2000, proportion2005, proportion2010, proportion2015;
    long int canada2000=0, canada2005=0, canada2010=0, canada2015=0;

    //Calculate total employees for each year in Canada
    for(int j=0; j<allRegions[9]->getSize(); j++)
        if(allRegions[9][0][j]->getYear()==2000)
            canada2000+=allRegions[9][0][j]->getNumEmployed();
    for(int j=0; j<allRegions[9]->getSize(); j++)
        if(allRegions[9][0][j]->getYear()==2005)
            canada2005+=allRegions[9][0][j]->getNumEmployed();
    for(int j=0; j<allRegions[9]->getSize(); j++)
        if(allRegions[9][0][j]->getYear()==2010)
            canada2010+=allRegions[9][0][j]->getNumEmployed();
    for(int j=0; j<allRegions[9]->getSize(); j++)
        if(allRegions[9][0][j]->getYear()==2015)
            canada2015+=allRegions[9][0][j]->getNumEmployed();

    //Get and calculate proportions for each region
    calcYear(2000, canada2000, proportion2000);
    calcYear(2005, canada2005, proportion2005);
    calcYear(2010, canada2010, proportion2010);
    calcYear(2015, canada2015, proportion2015);
    
    


    //Send proportions to outString
    ss<<left<<"Region  |"<<setw(9)<<"2000"<<"|"<<setw(9)<<"2005"<<"|"<<setw(9)<<"2010"<<"|"<<setw(9)<<"2015"<<endl;
    for(int i=0; i<allRegions.size(); i++)
        ss<<left<<setw(8)<< allRegions[i]->getProperty() <<"|"<<setw(6)<< proportion2000[i] <<"%  |"<<
           setw(6)<< proportion2005[i] <<"%  |"<<
           setw(6)<< proportion2010[i] <<"%  |"<<
           setw(6)<< proportion2015[i] <<"%  |"<<endl;
    
    outStr  = ss.str();
}

void EmploymentYear::calcYear(int y, int canada, vector<float>& proportions){
    
    for(int i=0; i<allRegions.size(); i++){
        int totalE = 0;
        float prop;
        //cout<<"i: "<<i<<endl;
        for(int j=0; j<allRegions[i]->getSize(); j++){
            //cout<<"j: "<<j<<endl;
            //allRegions[i]->print();
            if(allRegions[i][0][j]->getYear()==y){
                totalE+=allRegions[i][0][j]->getNumEmployed();
                //allRegions[i][0][j]->print();
            }
        }
        //Calculate, round, push to vector
        prop = ( (float)totalE/ (float)canada ) *100;
        prop = (int)(prop*1000 + .5);
        proportions.push_back( (float)prop /1000 );

        //cout<<allRegions[i][0][0]->getRegion()<<" - Total Employed: "<<totalE<<" Total canada: "<<canada
            //<<" - "<<prop/1000<<"%"<<endl;
    }
}