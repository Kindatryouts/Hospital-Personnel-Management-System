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

void EmployeesInput(){
                system("cls");
                cout<<"Adding" <<optionPro[choice-1]<<endl;
                cout<<"\nEnter your full name : ";
                cin>>emp.name;
                cout<<"Enter your Age :";
                cin>>emp.age;
            Gen:
                cout<<"Gender : \n Press 1 for Male \n Press 2 for Female\n";
                cin>>choice;
                if(choice==1)
                    emp.gender="Male";
                else if (choice==2)
                    emp.gender="Female";
                else
                    goto Gen;
            PN1:
                cout<<"Enter your phone number (+251 : ) ";
                cin>>emp.phoneNum;
                if(emp.phoneNum.length() != 9){
                    cout<<"\n  Please enter valid number ";
                    goto PN1;
                    }
            EDU1:

                for(short i=0;i<4;i++)
                {
                    cout<<" Press "<<i+1<<" for : "<<optionEdu[i]<<endl;
                }
                cin>>choice;
                if(choice<=0 && choice>4){
                    cout<<"Please enter valid number : ";
                    goto EDU1;
                }
                emp.eduLevel=optionPro[choice-1];
                file.open(emp.phoneNum+".txt",ios::out);
				if(file.is_open())
				{
				    file<<"Profession -> "<<emp.profession<<endl;
					file<<"Full name -> "<<emp.name<<endl;
                    file<<"Gender - > "<<emp.gender<<endl;
					file<<"Phone number -> +251"+emp.phoneNum<<endl;
					file<<"Profession -> "<<emp.profession<<endl;
					file<<"Education Level -> "<<emp.eduLevel<<endl;
					file<<"Salary -> "<<emp.salary;

					file.close();
				}
}
void addDoctor(){
    system("cls");
    cout<<"Adding A Doctor \n";
        if(countDoc<12)
            {
                cout<<"\nEnter full name : ";
                cin>>emp.name;
                cout<<"Enter your Age :";
                cin>>emp.age;
                emp.profession = "Doctor";
          Gen:
                cout<<"Gender : \n Press 1 for Male \n Press 2 for Female\n";
                cin>>choice;
                if(choice==1)
                    emp.gender="Male";
                else if (choice==2)
                    emp.gender="Female";
                else
                    goto Gen;
            PN1:
                cout<<"\nEnter your phone number (+251 : ) ";
                cin>>emp.phoneNum;
                if(emp.phoneNum.length() != 9){
                    cout<<"\n  Please enter valid number ";
                    goto PN1;
                }
            EDU1:
                string optionDoc[3]={"Specialist","Resident","GP"};


                for(short i=0;i<3;i++)
                {
                    cout<<" Press "<<i+1<<" for : "<<optionDoc[i]<<endl;
                }
                cin>>choice;
                if(choice<=0 && choice>3){
                    cout<<"Please enter valid number : ";
                    goto EDU1;
                }
                emp.eduLevel=optionDoc[choice-1];
                //setID();
            	file.open("Doctor.csv",ios::app);
				if(file.is_open())
				{
					file<<emp.name<<","<<emp.gender<<","<<"+251"+emp.phoneNum<<","<<emp.age<<","<<emp.profession<<","<<emp.eduLevel<<","<<emp.salary<<endl;

					file.close();

				}
            }
            countDoc++;
}
void addNurse(){
		if(countNur<24)
        {
            emp.profession=optionPro[1];
            EmployeesInput();
            file.open("Nurse.csv",ios::app);
            if(file.is_open())
            {
                file<<emp.name<<","<<emp.gender<<","<<"+251"+emp.phoneNum<<","<<emp.age<<","<<emp.profession<<","<<emp.eduLevel<<","<<emp.salary<<endl;
                file.close();
            }
        }
       countNur++;
}
void addLab(){
		if(countNur<6)
        {
            emp.profession=optionPro[2];
            EmployeesInput();
            file.open("Laboratory.csv",ios::app);
            if(file.is_open())
            {
                file<<emp.name<<","<<emp.gender<<","<<"+251"+emp.phoneNum<<","<<emp.age<<","<<emp.profession<<","<<emp.eduLevel<<","<<emp.salary<<endl;
                file.close();
            }
        }
       countLab++;
}
void addPhar(){
		if(countNur<6)
        {
            emp.profession=optionPro[3];
            EmployeesInput();
            file.open("Pharmacy.csv",ios::app);
            if(file.is_open())
            {
                file<<emp.name<<","<<emp.gender<<","<<"+251"+emp.phoneNum<<","<<emp.age<<","<<emp.profession<<","<<emp.eduLevel<<","<<emp.salary<<endl;
                file.close();
            }
        }
       countPha++;
}
void addIt(){
		if(countNur<3)
        {
            emp.profession=optionPro[4];
            EmployeesInput();
            file.open("IT.csv",ios::app);
            if(file.is_open())
            {
                file<<emp.name<<","<<emp.gender<<","<<"+251"+emp.phoneNum<<","<<emp.age<<","<<emp.profession<<","<<emp.eduLevel<<","<<emp.salary<<endl;
                file.close();
            }
        }
       countIt++;
}

void addFin(){
		if(countNur<3)
        {
            emp.profession=optionPro[5];
            EmployeesInput();
            file.open("Finance.csv",ios::app);
            if(file.is_open())
            {
                file<<emp.name<<","<<emp.gender<<","<<"+251"+emp.phoneNum<<","<<emp.age<<","<<emp.profession<<","<<emp.eduLevel<<","<<emp.salary<<endl;
                file.close();
            }
        }
       countFin++;
}
void addAss(){
		if(countAss<30)
        {
            emp.profession=optionPro[6];
            EmployeesInput();
            file.open("Medical Assistant.csv",ios::app);
            if(file.is_open())
            {
                file<<emp.name<<","<<emp.gender<<","<<"+251"+emp.phoneNum<<","<<emp.age<<","<<emp.profession<<","<<emp.eduLevel<<","<<emp.salary<<endl;
                file.close();
            }
        }
       countAss++;
}
void checker(){
    cout<<" \n  Press 'Y' to Go to Home Page  or  press any key to exit : ";
    cin>>check;
    if(check=='Y' || check=='y')
    	Display();
    else
    	exit(0);

}
void personal_info(string x){
    cout<<"\n\t=====  Your Personal informations  =====  "<<endl;
    file.open(x+".txt",ios::in);
    if(file.is_open())
    {
        system("cls");

        while(getline(file,fileRead))
        {
            cout<<fileRead<<endl;
        }
        file.close();
        cout<<"\n=====================================\n\n";
    }
}
