
#include "Control.h"

Control::Control(){
  View view;
  initReoprts();
}

void Control::launch()
{
  int choice = 5;
  while (1) {
    view.showMenu(choice, names);
    string out="";

    if (choice == 0)
      break;

    //Print report 1
    if (choice == 1) {
      reports[0]->execute(out);
      view.printStr(out);
    }

    //Print report 2
    if (choice == 2) {
      reports[1]->execute(out);
      view.printStr(out);
    }

    //Print report 3
    if (choice == 3) {
      reports[2]->execute(out);
      view.printStr(out);
    }

    //Print report 4
    if (choice == 4) {
      reports[3]->execute(out);
      view.printStr(out);
    }

    //Print report 5
    if (choice == 5) {
      reports[4]->execute(out);
      view.printStr(out);
    }

  }

  //Free up memory
  freeReports();
}

void Control::initReoprts()
{
  EmploymentAll* r1 = new EmploymentAll("Percents of graduates who get employed(in all regions)");
  reports.push_back(r1);
  names.push_back(r1->getName());

  EmploymentFemale* r2 = new EmploymentFemale("Top and Bottom 3 Regions for proportions of Female graduates");
  reports.push_back(r2);
  names.push_back(r2->getName());

  EmploymentYear* r3 = new EmploymentYear("Proportion of those employed in each region to the total employed in Canada (in all years)");
  reports.push_back(r3);
  names.push_back(r3->getName());

  DegreeReport* r4 = new DegreeReport("Most attained degree in each region");
  reports.push_back(r4);
  names.push_back(r4->getName());

  AverageReport* r5 = new AverageReport("Average number graduates from each region (in all years)");
  reports.push_back(r5);
  names.push_back(r5->getName());

  ReportGenerator::loadRecords();  
  ReportGenerator::loadPartials();
}

void Control::freeReports()
{
  for (size_t i = 0; i < reports.size(); i++)
    delete reports[i];  
}
