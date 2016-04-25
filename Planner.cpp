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
    m1->Event = "";
    m1->next = NULL;
    m1->previous= NULL;
    head = m1;

    Plans *m2 = new Plans;
    m2->Event = "";
    m2->next = NULL;
    m2->previous = m1;
    m1->next = m2;

    Plans *m3 = new Plans;
    m3->Event = "";
    m3->next = NULL;
    m3->previous = m2;
    m2->next = m3;

    Plans *m4 = new Plans;
    m4->Event = "";
    m4->next = NULL;
    m4->previous = m3;
    m3->next = m4;

    Plans *m5 = new Plans;
    m5->Event = "";
    m5->next = NULL;
    m5->previous = m4;
    m4->next = m5;

    Plans *m6 = new Plans;
    m6->Event = "";
    m6->next = NULL;
    m6->previous = m5;
    m5->next = m6;

   // Plans *m7 = new Plans;
   // m7-
    tail = m6;

}
