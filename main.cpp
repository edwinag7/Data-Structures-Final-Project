#include <iostream>
#include "Planner.h"

using namespace std;

int main()
{


    Planner test;
    int counter=0;
    string choice;
    string plantodelete;
    string plantime;
    string planname;
    string planvalue;
    string searchname;
    string searchtime;
    string priosearch;
    while(choice!="9")
    {
        cout<<"======Main Menu======"<<endl;
        cout<<"1. Add Plan to Schedule"<<endl;
        cout<<"2. Print All Plans"<<endl;
        cout<<"3. Delete Plan"<<endl;
        cout<<"4. Clear All Plans"<<endl;
        cout<<"5. Count the number of plans on the schedule currently"<<endl;
        cout<<"6. Search for an event by name"<<endl;
        cout<<"7. Search for event by time"<<endl;
        cout<<"8. Search for event by priority level"<<endl;
        cout<<"9. Quit"<<endl;
        cin>>choice;

        if(choice=="1"){
            cout<<"What is the name of this plan?"<<endl;
            cin.ignore();
            getline(cin,planname);
            cout<<"what time is this plan at?"<<endl;
            cin.ignore();
            getline(cin,plantime);
            cout<<"what is the priority level of this plan? On a scale 1 to 10. 10 being very important"<<endl;
            cin.ignore();
            getline(cin,planvalue);
            test.addEvent(plantime,planname,planvalue);
        }
        if(choice=="2"){
            test.printEvent();
        }
        if(choice == "3"){
            cout<<"What is the name of the plan you want to delete?"<<endl;
            cin.ignore();
            getline(cin, plantodelete);
            test.deleteEvent(plantodelete);
        }
        if(choice == "4"){
            test.clearPlanner();
        }
        if(choice=="5"){
            test.counter();
        }
        if(choice=="6"){
            cout<<"What is the plan name you would like to search your schedule for?"<<endl;
            cin.ignore();
            getline(cin,searchname);
            test.namesearchevent(searchname);
        }
        if(choice=="7"){
            cout<<"What is the time that you want to search on your schedule?"<<endl;
            cin.ignore();
            getline(cin,searchtime);
            test.timesearchevent(searchtime);
        }
        if(choice=="8"){
            cout<<"What is the priority level of the event you wish to search for?"<<endl;
            cin.ignore();
            getline(cin,priosearch);
            test.prioritysearchevent(priosearch);
        }

    }
    if(choice == "9"){
        cout<<"Good Bye"<<endl;
    }

    return 0;
}
