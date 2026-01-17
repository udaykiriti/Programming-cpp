//constructor overloading
#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H
#include<bits/stdc++.h>

class Inventoryitem
{
private:
    std::string description;
    double cost;
    int units;
public:
    Inventoryitem(/* args */){
        description="";
        cost=0.0;
        units=0;
    }
    Inventoryitem(std::string desc){
        description=desc;
        cost=0.0;
        units=0;
    }
    Inventoryitem(std::string desc,double c, int u){
        description=desc;
        cost=c;
        units=u;
    }
    void setDescription(std::string d){
        description=d;
    }
    void setCost(double c){
        cost=c;
    }
    void setUnits(int u){
        units=u;
    }
    std::string getDesc() const{
        return description;
    }
    double getCost() const{
        return cost;
    }
    int getUnits() const{
        return units;
    }
};
#endif