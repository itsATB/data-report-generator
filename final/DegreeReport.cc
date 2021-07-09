#include "ReportGenerator.h"

DegreeReport::DegreeReport(string s) : ReportGenerator(s)
{ }

DegreeReport::~DegreeReport()
{ }

void DegreeReport::execute(string& outStr){
    stringstream ss;
    vector<string> top;

    //Get and calculate proportions for each region
    for(int i=0;i<allRegions.size();i++)
        calcHighest(allRegions[i]->getProperty(), i, top);

    //Send proportions to outString
    ss<<left<<setw(8)<<"Region  |"<<setw(9)<<"Degree"<<endl;
    for(int i=0; i<allRegions.size(); i++)
        ss<<left<<setw(8)<< allRegions[i]->getProperty() <<"| "<<setw(6)<< top[i]<<endl;
    
    outStr  = ss.str();
}

void DegreeReport::calcHighest(string reg, int index, vector<string>& top){
    int doc=0, mast=0, bach=0, col=0;
    vector<int> degrees;
    string highest="";

    //calc numbers
    for(int i=0; i<allRegions[index]->getSize(); i++){
        if(allRegions[index][0][i]->getDegree()=="Doctorate")
            doc+=allRegions[index][0][i]->getNumGrads(); 
        if(allRegions[index][0][i]->getDegree()=="Master's")
            mast+=allRegions[index][0][i]->getNumGrads();
        if(allRegions[index][0][i]->getDegree()=="Bachelor's")
            bach+=allRegions[index][0][i]->getNumGrads();
        if(allRegions[index][0][i]->getDegree()=="College")
            col+=allRegions[index][0][i]->getNumGrads();
        //cout<<"-D: "<<doc<<" -M: "<<mast<<" -B: "<<bach<<" -C:"<<col<<endl;
    }
    degrees.push_back(doc); degrees.push_back(mast); 
    degrees.push_back(bach); degrees.push_back(col);
    //cout<<"Final: -D: "<<doc<<" -M: "<<mast<<" -B: "<<bach<<" -C:"<<col<<endl;

    //Sort list
    int temp;
    for(int i=0;i<degrees.size();i++)
	{		
		for(int j=i+1;j<degrees.size();j++)
		{
			if(degrees[i]>degrees[j])
			{
				temp  =degrees[i];
				degrees[i]=degrees[j];
				degrees[j]=temp;
			}
		}
	}

    //Get highest
    if(degrees[3]==doc)
        highest = "Doctorate";
    if(degrees[3]==mast)
        highest = "Master";
    if(degrees[3]==bach)
        highest = "Bachelor";
    if(degrees[3]==col)
        highest = "College";
    top.push_back(highest);
}