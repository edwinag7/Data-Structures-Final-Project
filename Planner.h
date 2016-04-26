#ifndef PLANNER_H
#define PLANNER_H
#include <iostream>
using namespace std;


struct Plans{
    string Event;
    string Values;
    string Time;
    Plans *next;
    Plans *previous;
    Plans(){};
    Plans(string initTime, string initEvent, string initValues, Plans *initnext, Plans *initprevious){
        Event=initEvent;
        Values=initValues;
        Time=initTime;
        next=initnext;
        previous=initprevious;
    }


};
class Planner
{
    public:
        Planner();
        ~Planner();
        void buildNetwork();
        void addEvent(string time, string planname, string planvalue);
        void deleteEvent(string event);
        void traverse();
        void printEvent();
        void clearPlanner();
        void OrganizeTime(string time);
        void OrganizePriority(int Level);
        void OrganizeAlpha(string Letters);


    protected:
    private:
        Plans *head = NULL;
        Plans *tail = NULL;
};

#endif // PLANNER_H
