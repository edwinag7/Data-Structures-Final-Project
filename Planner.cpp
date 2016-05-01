#include "Planner.h"

Planner::Planner()
{
    head = NULL;
}

Planner::~Planner()
{
    //dtor
}
void Planner::clearPlanner(){
     Plans *tmp=head;
     while(tmp!=NULL){
         head=head->next;
         delete head;
         tmp=head;
     }
     cout<<"Schedule cleared"<<endl;

}
void Planner::printEvent(){
    Plans *tmp=NULL;
    tmp=head;
    int counter=0;
    while(tmp!=NULL){
        cout<<"==="<<endl;
        cout<<"Time: "<<tmp->Time<<endl;
        cout<<"Priority: "<<tmp->Values<<endl;
        cout<<"Name: "<<tmp->Event<<endl;
        tmp=tmp->next;
        counter++;
        cout<<"==="<<endl;
    }
    if (counter==0){
        cout<<"There are currently no plans on your schedule"<<endl;
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
        cout<<"Event Added"<<endl;
}
void Planner::counter(){
    int counter=0;
    Plans *tmp=head;
    while(tmp!=NULL){
        tmp=tmp->next;
        counter++;
    }
    cout<<"You currently have "<<counter<<" plans on your schedule"<<endl;
}

void Planner::deleteEvent(string Eventdelete)
{
    Plans *current=head;
    Plans *deleteplan= new Plans;

    while (deleteplan->Event!=Eventdelete && current->next!=NULL)
    {
        current=current->next;
    }
    if(head->Event==Eventdelete){
        Plans *tmp=head;
        head=head->next;
        delete tmp;
    }
    else if(current->next==NULL)
    {
        deleteplan = current;
        deleteplan->previous->next=deleteplan->next;  //error here
        delete deleteplan;

    }
    else
    {
        deleteplan=current;
        deleteplan->previous->next=deleteplan->next;
        deleteplan->next->previous=deleteplan->previous;
        delete deleteplan;
    }

}
void Planner::namesearchevent(string eventname){
        Plans *tmp=head;

        while(tmp!=NULL){

            if(tmp->Event==eventname){
                cout<<"Event found!"<<endl;
                cout<<"This event is at the time: "<<tmp->Time<<" ,and has a priority value of: "<<tmp->Time<<endl;
                return;
            }
            else{
                tmp=tmp->next;
            }
        }
        cout<<"No event found under this name"<<endl;
}
void Planner::timesearchevent(string eventtime){
        Plans *tmp=head;

        while(tmp!=NULL){
            if(tmp->Time==eventtime){
                cout<<"Event found!"<<endl;
                cout<<"At this time you have an event named: "<<tmp->Event<<" ,and it has a priority level of: "<<tmp->Values<<endl;
                return;
            }
            else{
                tmp=tmp->next;
            }
        }
        cout<<"No event found at this time"<<endl;
}
void Planner::prioritysearchevent(string eventprio){
        Plans *tmp=head;
        while(tmp!=NULL){
            if(tmp->Values==eventprio){
                cout<<"Event found!"<<endl;
                cout<<"You have an event under this priority level called: "<<tmp->Event<<" ,and it is schedule for the time: "<<tmp->Time<<endl;
                return;
            }
            else{
                tmp=tmp->next;
            }
        }
        cout<<"No event found under this priority level"<<endl;
}
void Planner::sortbyprio(){
    Plans *tmp=head;
    Plans *timearr[100];
    int counter=0;
    if(head == NULL){
        cout<<"There are no plans in the planner"<<endl;
    }
    else{
        if(head->next==NULL){
            cout<<head->Event<<" has a priority level of: "<<head->Values<<endl;
            cout<<"This is the only plan on your schedule currently"<<endl;
            return;
        }
        while(tmp!=NULL){
            timearr[counter]=tmp;
            counter++;
            tmp=tmp->next;
        }

    int count2=0;
        for(int p=0;p<counter;p++){

                count2=count2+1;

        }
        Plans *swap1=NULL;
        for(int i=0; i<counter-1; i++)
        {
            for(int j=0; j<counter-1; j++)
            {
                if(timearr[j]->Values<timearr[j+1]->Values)
                {
                    swap1=timearr[j];
                    timearr[j]=timearr[j+1];
                    timearr[j+1]=swap1;

                }

            }
        }

        for(int x=0; x<counter; x++){
            cout<<"Plan Name: "<<timearr[x]->Event<<"  has a priority of: "<<timearr[x]->Values<<" and is scheduled for time: "<<timearr[x]->Time<<endl;
        }
    }
}
bool Planner::scheduleConflict()
{
    Plans *tmp = new Plans;
    Plans *tmp2 = new Plans;
    while (tmp != NULL && tmp2 != NULL)
    {
        if (tmp->Time != tmp2->Time)
        /* If we reach here, then a and b are not NULL and
           their data is same, so move to next nodes in both
           lists */
        tmp = tmp->next;
        tmp2 = tmp2->next;
        cout<<"There are multiple events at one time - there is a conflict"<<endl;
        return false;
    }

    // If linked lists are identical, then 'a' and 'b' must
    // be NULL at this point.
    return (tmp == NULL && tmp2 == NULL);
    cout<<"there our no conflicts on the schedule"<<endl;

}

bool Planner::checkPlanExists(string plan){
    Plans *current = head;
    while(current != NULL){
        if(current->Event == plan){
            return true;
        }
    }
    return false;
}
