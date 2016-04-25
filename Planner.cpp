#include "Planner.h"

Planner::Planner()
{
    head=NULL;
}

Planner::~Planner()
{
    //dtor
}

void Planner::printEvent(){

    Plans *tmp=NULL;
    tmp=head;
    while(tmp!=NULL){
        cout<<"Time "<<tmp->Time<<endl;
        cout<<"Values "<<tmp->Values<<endl;
        cout<<"Event "<<tmp->Event<<endl;
        tmp=tmp->next;
    }

}

void Planner::addEvent(string time, string planname, string planvalue)
{
        if(head==NULL){
            Plans *test=new Plans(time, planname, planvalue, NULL,NULL);
            head=test;
        }

        else{
        Plans *current = head;
        while(current->next!=NULL){
            current=current->next;
        }

        Plans *addPlan=new Plans(time, planname, planvalue, NULL, NULL);
        addPlan->next=current->next;
        addPlan->previous=current;
        current->next=addPlan;
        }
}
