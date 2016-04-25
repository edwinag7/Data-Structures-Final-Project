#ifndef PLANNER_H
#define PLANNER_H
#include <iostream>
using namespace std;
struct Plans{
    string Event;
    string Values;
    Plans *next;
    Plans *previous;
    Plans(){};

};
class Planner
{
    public:
        Planner();
        ~Planner();
        void buildNetwork();
        void addEvent(string event);
        void deleteEvent(string event);
        void traverse();
        void printEvent();
        void clearPalnner();
        void OrganizeTime(string time);
        void OrganizePriority(int Level);
        void OrganizeAlpha(string Letters);


    protected:
    private:
        Plans *head = NULL;
        Plans *tail = NULL;
};

#endif // PLANNER_H
