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

