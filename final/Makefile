OBJ = main.o Record.o ReportGenerator.o EmploymentAll.o EmploymentFemale.o EmploymentYear.o DegreeReport.o AverageReport.o Control.o View.o

OPT = 

f: $(OBJ)
	g++ $(OPT) -o f $(OBJ)

main.o: main.cc
	g++ $(OPT) -c main.cc

Record.o: Record.cc Record.h
	g++ $(OPT) -c Record.cc

ReportGenerator.o: ReportGenerator.cc ReportGenerator.h Property.h
	g++ $(OPT) -c ReportGenerator.cc

EmploymentAll.o: EmploymentAll.cc
	g++ $(OPT) -c EmploymentAll.cc

EmploymentFemale.o: EmploymentFemale.cc
	g++ $(OPT) -c EmploymentFemale.cc

EmploymentYear.o: EmploymentYear.cc
	g++ $(OPT) -c EmploymentYear.cc

DegreeReport.o: DegreeReport.cc
	g++ $(OPT) -c DegreeReport.cc

AverageReport.o: AverageReport.cc
	g++ $(OPT) -c AverageReport.cc

View.o: View.cc View.h
	g++ $(OPT) -c View.cc

Control.o: Control.cc Control.h
	g++ $(OPT) -c Control.cc

clean:
	rm -f *.o f
