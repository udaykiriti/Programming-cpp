#include<bits/stdc++.h>
using  namespace std;
#include "Budget.h"

int main(){
    int count;
    const int NUM_DIVISIONS=4;
    Budget divisions[NUM_DIVISIONS];
    for ( count = 0; count< NUM_DIVISIONS; count++)
    {
        double budgetamount;
        cout<<"enter the budgent request amount"<<count+1<<":";
        cin>>budgetamount;
        divisions[count].addBudget(budgetamount);
    }   
    cout << fixed << showpoint << setprecision(2);
    cout << "\nHere are the division budget requests:\n";
    for (count = 0; count < NUM_DIVISIONS; count++)
    {
        cout << "\tDivision " << (count + 1) << "\t$ ";
        cout << divisions[count].getDivisionBudget() << endl;
    }
    cout << "\tTotal Budget Requests:\t$ ";
    cout << divisions[0].getcorpBudget() << endl;
}