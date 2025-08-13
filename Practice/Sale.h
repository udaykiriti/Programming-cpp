#ifndef SALE_H
#define SALE_H

class Sale{
    private:
        double itemCost;
        double taxRate;
    public:
        Sale(double cost,double rate){
            itemCost=cost;
            taxRate=rate;
        }
        double getCost() const{
            return itemCost;
        }
        double getTaxRate() const{
            return taxRate;
        }
        double getTax() const{ 
            return (itemCost * taxRate); 
        }
        double getTotal() const{ 
            return (itemCost + getTax()); 
        }
};
#endif