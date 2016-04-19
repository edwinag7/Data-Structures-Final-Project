#include <iostream>
#include "Planner.h"

using namespace std;

int main()
{
    string Pop;
    cout<<"What are your plans for today?"<<endl;
    cin>>Pop;
    Planner WTF;
    WTF.buildNetwork();

    return 0;
}
