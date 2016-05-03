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
        void addEvent(string time, string planname, string planvalue);
        void printEvent();
        void clearPlanner();
        void counter();
        void deleteEvent(string Eventdelete);
        void namesearchevent(string eventname);
        void timesearchevent(string eventtime);
        void prioritysearchevent(string eventprio);
        void sortbyprio();
        bool scheduleConflict();

        bool checkPlanExists(string plan);

    protected:
    private:
        Plans *head = NULL;
        Plans *tail = NULL;

};

#endif // PLANNER_H
