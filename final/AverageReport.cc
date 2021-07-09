#include "ReportGenerator.h"

AverageReport::AverageReport(string s) : ReportGenerator(s)
{ }

AverageReport::~AverageReport()
{ }

void AverageReport::execute(string& outStr){
    stringstream ss;
    vector<float> avg2000, avg2005, avg2010, avg2015;
    int canada2000=0, canada2005=0, canada2010=0, canada2015=0;

    //Calculate total graduates for each year in Canada
    for(int j=0; j<allRegions[9]->getSize(); j++)
        if(allRegions[9][0][j]->getYear()==2000)
            canada2000+=allRegions[9][0][j]->getNumGrads();
    for(int j=0; j<allRegions[9]->getSize(); j++)
        if(allRegions[9][0][j]->getYear()==2005)
            canada2005+=allRegions[9][0][j]->getNumGrads();
    for(int j=0; j<allRegions[9]->getSize(); j++)
        if(allRegions[9][0][j]->getYear()==2010)
            canada2010+=allRegions[9][0][j]->getNumGrads();
    for(int j=0; j<allRegions[9]->getSize(); j++)
        if(allRegions[9][0][j]->getYear()==2015)
            canada2015+=allRegions[9][0][j]->getNumGrads();

    //Calculate averages for each region
    for(int i=0;i<allRegions.size();i++)
        calcAvg(allRegions[i]->getProperty(), i, canada2000, avg2000);
    for(int i=0;i<allRegions.size();i++)
        calcAvg(allRegions[i]->getProperty(), i, canada2005, avg2005);
    for(int i=0;i<allRegions.size();i++)
        calcAvg(allRegions[i]->getProperty(), i, canada2010, avg2010);
    for(int i=0;i<allRegions.size();i++)
        calcAvg(allRegions[i]->getProperty(), i, canada2015, avg2015);

    //Send to outString
    ss<<left<<"Region  |"<<setw(9)<<"2000"<<"|"<<setw(9)<<"2005"<<"|"<<setw(9)<<"2010"<<"|"<<setw(9)<<"2015"<<endl;
    for(int i=0; i<allRegions.size(); i++)
        ss<<left<<setw(8)<< allRegions[i]->getProperty() <<"|"<<setw(6)<< avg2000[i] <<"%  |"<<
           setw(6)<< avg2005[i] <<"%  |"<<
           setw(6)<< avg2010[i] <<"%  |"<<
           setw(6)<< avg2015[i] <<"%  |"<<endl;
    
    outStr  = ss.str();
}

void AverageReport::calcAvg(string reg, int index, int canada, vector<float>& avgs){
    //Get total for region
    for(int i=0; i<allRegions.size(); i++){
        int totalE = 0;
        float avg;
        //cout<<"i: "<<i<<endl;
        for(int j=0; j<allRegions[i]->getSize(); j++){
            //cout<<"j: "<<j<<endl;
            //allRegions[i]->print();
            if(allRegions[i][0][j]->getRegion()==reg){
                totalE+=allRegions[i][0][j]->getNumGrads();
                //allRegions[i][0][j]->print();
            }
        }
        //Calculate, round, push to vector
        avg = ( (float)totalE/ (float)canada )*100 ;
        avg = (int)(avg*1000 + .5);
        avgs.push_back( (float)avg /1000 );

        //cout<<allRegions[i][0][0]->getRegion()<<" - Total grads: "<<totalE<<" Total canada: "<<canada
            //<<" - "<<avg<<endl;
    }
}