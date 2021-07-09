#ifndef PROPERTY_H
#define PROPERTY_H

#include<vector>
#include <iostream>
using namespace std;

#include "Record.h"

template <class T>
class Property
{
public:
    Property(T);
    ~Property();
    Property& operator+=(Record*);
    Record* operator[](int);
    T getProperty();
    int getSize();
    void print();
private:
    T property;
    vector<Record*> records;
};

template <class T>
Property<T>::Property(T p) : property(p) {}

template <class T>
Property<T>::~Property(){
    records.clear();
}

template <class T>
Property<T>& Property<T>::operator+=(Record* r){
    records.push_back(r);
    return *this;
}

template <class T>
Record* Property<T>::operator[](int i){
    return records[i];
}

template <class T>
T Property<T>::getProperty(){   return property; }

template <class T>
int Property<T>::getSize(){  return records.size();    }

template <class T>
void Property<T>::print(){
    cout<<"---List of records (Property):"<<endl;
    for (int i=0; i<records.size(); i++){
        cout<<i<<". "; 
        records[i]->print();
    }
    //records[0]->print();
}

#endif