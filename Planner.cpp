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
}
