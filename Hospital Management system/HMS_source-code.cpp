#include <iostream>
#include<iomanip>
#include<fstream>
#include<ctime>

using namespace std;

struct employee{
    string name;
    string id;
    int age;
    string gender;
    string eduLevel;
    string phoneNum;
    string profession;
    bool attendance;  // daily attendance
    double performance;  //out of 10 or 100
    int numofEmp;
    string salary;
    string workingSchedule; // include ward program + 8 hr per 24hr
    string breakSchedule; // annual break 14 day for every emp
    double numofAttendance ;
    double numofWard;
    double mngtScore; // score given by their managers

};

int countDoc,countNur,countLab,countPha,countIt,countFin,countAss,countAll;
fstream file;
string fileRead;
string optionEdu[4]={"PHD","Masters","Degree","Diploma"};
string optionAdd[9]={"All","Doctor","Nurse", "Labratorist","Pharmacist", "It Technician", "Finance", "Medical Assistant","Go Back"};
string optionPage[4]={"Manager page","Employee page","Contact us","Exit"};
string optionPro[8]={"Doctor","Nurse","Laboratorist","Pharmacist","IT Technician","Finance","Assistant","Go back"};
int choice;
char check;
employee emp;

void setID();
void Display();
void addEmployee();
void showAllEmployee();
void showDoctors();
void showNurses();
void showLaboratorists();
void showPharmacists();
void showIT();
void showFinance();
void showAssistants();
void addDoctor();
void addNurse();
void addLab();
void addPhar();
void addIt();
void addFin();
void addAss();
void Terminate_employee();

void setID(){
      emp.id=emp.profession[0]+emp.profession[1]+emp.phoneNum[5]+emp.phoneNum[6]+emp.phoneNum[7]+emp.phoneNum[8];
}


