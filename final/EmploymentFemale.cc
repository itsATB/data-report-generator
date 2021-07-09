#include "ReportGenerator.h"

EmploymentFemale::EmploymentFemale(string s) : ReportGenerator(s)
{ }

EmploymentFemale::~EmploymentFemale()
{ }

void EmploymentFemale::execute(string& outStr){
    stringstream ss;
    vector<float> bottom, top;
    vector<string> topRegions, bottomRegions;

    //Calc top
    calcTop(top, topRegions);    
    
    //Calc bottom
    calcBottom(bottom,bottomRegions);

    //Send to outstring
    ss<<"Region       |    Proportion       "<<endl;

    ss<<"Top 3:               "<<endl;
    for(int i=0; i<top.size(); i++)
        ss<<i+1<<". "<< topRegions[i] <<"        |       "<< top[i] <<"%       |"<<endl;
        
    ss<<"Bottom 3:               "<<endl;
    for(int i=0; i<bottom.size(); i++)
        ss<<i+1<<". "<< bottomRegions[i] <<"        |       "<< bottom[i] <<"%       |"<<endl;

    outStr  = ss.str();
}

void EmploymentFemale::calcTop(vector<float>& top, vector<string>& topRegions){
    vector<float> proportions, ordered;
    vector<string> regions, orderedRegions;

    //Calculate proportions
    for(int i=0; i<allRegions.size(); i++){
        float prop;        
        int totalF=0, totalG=0;
        for(int j=0; j<allRegions[i]->getSize(); j++){
            totalG+=allRegions[i][0][j]->getNumGrads();
            if(allRegions[i][0][j]->getGender() == "Females")
                totalF+=allRegions[i][0][j]->getNumGrads();
        }

        //Calculate, round, push to vector
        prop = ( (float)totalF/(float)totalG ) *100;
        prop = (int)(prop*1000 + .5);
        proportions.push_back( (float)prop /1000 );
        regions.push_back( allRegions[i][0][0]->getRegion() );
        
        //cout<<allRegions[i][0][0]->getRegion()<<" - Total Females: "<<totalF<<" Total graduates: "<<totalG
            //<<" - "<<prop/1000<<"%"<<endl;
    }

    //Order Proportions
    for(int j=0; j<3; j++){
        float highest=0;
        for(int i=0;i<proportions.size();i++){
            if(proportions[i] > highest){
                highest = proportions[i];
                ordered.push_back(proportions[i]);
                orderedRegions.push_back(regions[i]);
                continue;
            }
        }
    }

    //Get highest ones
    for(int i=ordered.size()-1; i>=9; i--){
        top.push_back(ordered[i]);
        topRegions.push_back(orderedRegions[i]);
    }
}

void EmploymentFemale::calcBottom(vector<float>& bottom, vector<string>& bottomRegions){
    vector<float> proportions, ordered;
    vector<string> regions, orderedRegions;

    //Calculate proportions
    for(int i=0; i<allRegions.size(); i++){
        float prop;        
        int totalF=0, totalG=0;
        for(int j=0; j<allRegions[i]->getSize(); j++){
            totalG+=allRegions[i][0][j]->getNumGrads();
            if(allRegions[i][0][j]->getGender() == "Females")
                totalF+=allRegions[i][0][j]->getNumGrads();
        }

        //Calculate, round, push to vector
        prop = ( (float)totalF/(float)totalG ) *100;
        prop = (int)(prop*1000 + .5);
        proportions.push_back( (float)prop /1000 );
        regions.push_back( allRegions[i][0][0]->getRegion() );
        
        //cout<<allRegions[i][0][0]->getRegion()<<" - Total Females: "<<totalF<<" Total graduates: "<<totalG
            //<<" - "<<prop/1000<<"%"<<endl;
    }

    //Sort  Proportions
    float temp;
    string tmp;
    for(int i=0;i<proportions.size();i++)
	{		
		for(int j=i+1;j<proportions.size();j++)
		{
			if(proportions[i]>proportions[j])
			{
				temp  =proportions[i];
				proportions[i]=proportions[j];
				proportions[j]=temp;
                tmp  =regions[i];
				regions[i]=regions[j];
				regions[j]=tmp;
			}
		}
	}
    
    //Get bottom ones
    for(int i=0; i<3; i++){
        bottom.push_back(proportions[i]);
        bottomRegions.push_back(regions[i]);
    }
}

template <typename T>
void sort(vector<T>& arr){
    T temp;
    for(int i=0;i<arr.size();i++)
	{		
		for(int j=i+1;j<arr.size();j++)
		{
			if(arr[i]>arr[j])
			{
				temp  =arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
}