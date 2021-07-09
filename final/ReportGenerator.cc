#include "ReportGenerator.h"

vector<Record*> ReportGenerator::recordsPrime;
vector< Property<int>* > ReportGenerator::allYears;
vector< Property<string>* > ReportGenerator::allRegions;
vector< Property<string>* > ReportGenerator::allDegrees;
vector< Property<string>* > ReportGenerator::allGenders;
bool ReportGenerator::isfreed=0;

ReportGenerator::ReportGenerator(string n) : name(n)
{    
    cout<<"-- ReportGenerator ctor: "<<name<<endl;
}

ReportGenerator::~ReportGenerator(){    
    //cout<<"isfreed: "<<isfreed<<endl;
    if(isfreed==0){
        for (int i=0; i<recordsPrime.size(); ++i)
           delete recordsPrime[i];

        for (int i=0; i<allYears.size(); ++i)
            delete allYears[i];         
        for (int i=0; i<allRegions.size(); ++i)
            delete allRegions[i];
        for (int i=0; i<allDegrees.size(); ++i)
            delete allDegrees[i];
        for (int i=0; i<allGenders.size(); ++i)
            delete allGenders[i];

        isfreed=1;
        //cout<<"isfreed: "<<isfreed<<endl;
    }
    cout<<"-- ReportGenerator dtor: "<<name<<endl;
}

void ReportGenerator::loadRecords(){
    try
    {
        int y, ng, ne;
        string deg,gen,reg;

        ifstream infile("grad.dat", ios::in);
        if (!infile) {
            cout << "Error: could not open file" << endl;
            exit(1);
        }

        while( infile >> y>> reg>> deg>> gen>> ne>> ng){
            Record* rec = new Record(y,reg,deg,gen,ne,ng);
            recordsPrime.push_back(rec);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr <<"--- Error while loading records from 'grades.dat'"<< '\n';
    }    
}

//fills each partial collection with the records of 
//the corresondinig type
void ReportGenerator::loadPartials(){
    //allYears
    int arr[] = {2000,2005,2010,2015};
    int size = sizeof(arr)/sizeof(arr[0]); 
    for(int i=0;i<size;i++){
        int n=arr[i];
        Property<int>* p = new Property<int>(n);
        for (int i=0; i<recordsPrime.size(); ++i){
            if (recordsPrime[i]->getYear()==n){
                //cout<<"adding: "<<endl;recordsPrime[i]->print();
                *p+=recordsPrime[i]; 
            }
        }
        allYears.push_back(p);
        //ptr->print();
        //allYears[i]->print();
        //cout<<allYears.size()<<endl;
    }

    //allregions   
    string arr2[] = {"NL","PE","NS","QC","ON","NB","SK","AB","BC","CAN"};
    size = sizeof(arr2)/sizeof(arr2[0]);     
    for(int i=0;i<size;i++){
        string n=arr2[i];
        Property<string>* p = new Property<string>(n);
        for (int i=0; i<recordsPrime.size(); ++i){
            if (recordsPrime[i]->getRegion()==n)
                *p+=recordsPrime[i];
        }
        allRegions.push_back(p);
    }

    string arr3[] = {"Doctorate","Master's","Bachelor's","College"};
    size = sizeof(arr3)/sizeof(arr3[0]); 
    for(int i=0;i<size;i++){
        string n=arr3[i];
        Property<string>* p = new Property<string>(n);
        for (int i=0; i<recordsPrime.size(); ++i){
            if (recordsPrime[i]->getDegree()==n){
                *p+=recordsPrime[i]; 
            }
        }
        allDegrees.push_back(p);
    }
    

    string arr4[] = {"Males","Females","All"};
    size = sizeof(arr4)/sizeof(arr4[0]); 
    for(int i=0;i<size;i++){
        string n=arr4[i];
        Property<string>* p = new Property<string>(n);
        for (int i=0; i<recordsPrime.size(); ++i){
            if (recordsPrime[i]->getGender()==n){
                *p+=recordsPrime[i]; 
            }
        }
        allGenders.push_back(p);
    }
    

} 

string ReportGenerator::getName(){  return name; }
