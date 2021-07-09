#include <iostream>
using namespace std;
#include <string>
#include <vector>

#include "View.h"

void View::showMenu(int& choice, vector<string> names)
{
  cout << endl << endl;
  cout << "Which report would you like to view:"<< endl;
  for(int i=0;i<names.size();i++)
    cout << "  ("<<i+1<<") "<< names[i] << endl;
  /*cout << "  (1) "<< names[0] << endl;
  cout << "  (2) "<< names[1] << endl;
  cout << "  (3) "<< names[3] << endl;
  cout << "  (4) "<< names[3] << endl;
  cout << "  (5) "<< names[4] << endl;*/
  cout << "  (0) Exit" << endl<<endl;

  cout << "Enter your selection: ";
  cin >> choice;
  if (choice == 0)
    return;

  while (choice < 1 || choice > 5) {
    cout << "Enter your selection: ";
    cin >> choice;
  }

}

void View::printStr(string str)
{
  cout << str;
}

void View::readInt(int& n)
{
  cin >> n;
}

void View::readStr(string& str)
{
  cin >> str;
}
