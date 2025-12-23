#include<bits/stdc++.h>
using namespace std;
#include "Sale.h"

int main(void){
    double cost;
    double taxx=0.6;
    cout<<"enter tax and cost : ";
    cin>>cost;
    Sale itemsale(taxx,cost);
    cout<<itemsale.getTax()<<endl;
    cout<<itemsale.getCost()<<endl;
    cout<<itemsale.getTaxRate()<<endl;
    cout<<itemsale.getTotal()<<endl;
}