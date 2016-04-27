#include <iostream>
#include "Planner.h"

using namespace std;

int main()
{
    /*
    string Pop;
    cout<<"What are your plans for today?"<<endl;
    cout<<"1. If you want to add an event."<<endl;
    cout<<"2. If you want to delete an event."<<endl;
    cout<<"3. If you want sort your Schedule through time, priority, or alphabetically."<<endl;
    cout<<"4. To view your complete schedule."<<endl;
    cout<<"5. To delete your entire schedule."<<endl;
    cout<<"7. To Quit"<<endl;
    cin>>Pop;
    */
   // Planner WTF;
   // WTF.buildNetwork();
    Planner test;
    int counter=0;
    string choice;
    string plantime;
    string planname;
    string planvalue;
    while(choice!="5")
    {
        cout<<"======Main Menu======"<<endl;
        cout<<"1. Add Event"<<endl;
        cout<<"2. Print All Plans"<<endl;
        cout<< "3. Delete Plan"<<endl;
        cout<<"4. Clear All Plans"<<endl;
        cout<<"5. Quit"<<endl;
        cin>>choice;

        if(choice=="1"){
            cout<<"What is the name of this plan?"<<endl;
            cin.ignore();
            getline(cin,planname);
            cout<<"What time is this plan at?"<<endl;
            getline(cin,plantime);
            cout<<"What's the priority of this plan? On a scale 1 to 10, 10 being very important"<<endl;
            cin>>planvalue;
            test.addEvent(plantime,planname,planvalue);

        }
        if(choice=="2"){

            test.printEvent();
        }

    }


    return 0;
}
