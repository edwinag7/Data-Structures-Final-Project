#ifndef PLANNER_H
#define PLANNER_H
#include <iostream>
using namespace std;
struct Plans{
    string Event;
    int Values;
    string Time;
    int Day;
    Plans *next;
    Plans *previous;
    Plans(){};
/*
 Plans(string initName, Plans *initNext, Plans *initprevious, string initvalue, string initTime)
    {
        Event = initName;
        next = initNext;
        previous = initprevious;
        Values = initvalue;
        Time=initTime;
    }*/
};
class Planner
{
    public:
        Planner();
        ~Planner();
        void buildNetwork();
        void printallplans();
        void addPlan(string time, string planname, string planvalue);
        void addEvent(string event);
        void deleteEvent(string event);
        void traverse();
        void printEvent();
        void clearPalnner();
        void OrganizeTime(string time);
        void OrganizeAlpha(string Letters);


    protected:
    private:
        Plans *head = NULL;
        Plans *tail= NULL;
};

#endif // PLANNER_H
