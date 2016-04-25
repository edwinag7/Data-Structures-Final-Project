#include "Planner.h"

Planner::Planner()
{
    //ctor
}

Planner::~Planner()
{
    //dtor
}

void Planner::buildNetwork(){
    Plans *m1 = new Plans;
    m1->Event = "Doctor's apt.";
    m1->Values=7;
    m1->Day=1;
    m1->next =NULL;
    m1->previous= NULL;
   Plans *head = m1;

    Plans *m2 = new Plans;
    m2->Event = "Dentist apt.";
    m2->Day=2;
    m2->Values=6;
    m2->next = NULL;
    m2->previous = m1;
    m1->next = m2;

    Plans *m3 = new Plans;
    m3->Day=3;
    m3->Values=8;
    m3->Event = "Meeting";
    m3->next = NULL;
    m3->previous = m2;
    m2->next = m3;

    Plans *m4 = new Plans;
    m4->Day=4;
    m4->Values=5;
    m4->Event = "Lunch date";
    m4->next = NULL;
    m4->previous = m3;
    m3->next = m4;

    Plans *m5 = new Plans;
    m5->Day=5;
    m5->Values=3;
    m5->Event = "Clean room";
    m5->next = NULL;
    m5->previous = m4;
    m4->next = m5;

    Plans *m6 = new Plans;
    m6->Day=6;
    m6->Values=2;
    m6->Event = "Mow lawn";
    m6->next = NULL;
    m6->previous = m5;
    m5->next = m6;
    Plans *tmp=head;
    tail=m6;
}

void Planner::printEvent(){
   /*
    Plans *tmp=NULL;
    tmp=head;
    while(tmp!=NULL){
        cout<<tmp->Day<<endl;
        cout<<tmp->Values<<endl;
        cout<<tmp->Event<<endl;
        tmp=tmp->next;
    }
    */
    Plans* tmp = head;
    //returnNode = NULL;
    cout<< "===CURRENT PATH===" <<endl;
    while(tmp != NULL){
        cout<<tmp->Event<<" -> ";
        tmp = tmp->next;
    }
     cout<<"NULL"<<endl;
    cout<<"=================="<<endl;

}


void Planner::addEvent(string time, string planname, string planvalue)
{
        Plans *current = head;
        Plans *addPlan= new Plans;
        cout<<"1"<<endl;
        while (current != NULL){
            if (current-> Event == time){

            cout<<"2"<<endl;
            addPlan->next=current->next;
            current->next=addPlan;
        }
        }
            cout<<"3"<<endl;
        addPlan->Event=planname;
        addPlan->Values=planvalue;
        addPlan->Time=time;
        addPlan->next=current->next;
        addPlan->previous=current->next->previous;
        current->next->previous=addPlan;
        current->next=addPlan;
}

