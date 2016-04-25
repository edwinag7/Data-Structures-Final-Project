#include <iostream>
#include "Planner.h"
using namespace std;

int main()
{
    Planner test;
    int counter=0;
    string choice;
    string plantime;
    string planname;
    string planvalue;
    while(choice!="5")
    {
        cout<<"======Main Menu======"<<endl;
        cout<<"1. Build Network"<<endl;
        cout<<"2. Print All Plans"<<endl;
        cout<< "3. Delete Plan"<<endl;
        cout<<"4. Clear All Plans"<<endl;
        cout<<"5. Quit"<<endl;
        cin>>choice;

        if(choice=="1"){
            test.buildNetwork();
            /*cout<<"What is the name of this plan?"<<endl;
            cin.ignore();
            getline(cin,planname);
            cout<<"what time is this plan at?"<<endl;
            cin.ignore();
            getline(cin,plantime);
            cout<<"what is the priority level of this plan? On a scale 1 to 10. 10 being very important"<<endl;
            cin.ignore();
            getline(cin,planvalue);
            test.addPlan(plantime,planname,planvalue);*/

        }
        if(choice=="2"){
            test.printallplans();
        }

    }
    return 0;
}
