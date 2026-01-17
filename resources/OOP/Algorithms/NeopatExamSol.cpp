#include <bits/stdc++.h>
using namespace std;

class Employee {
public:
    int empid;
    string salaryStr;
    float salary;

    Employee(int id, string sal) {
        empid = id;
        salaryStr = sal;
        stringstream ss(sal);
        ss >> salary;
    }

protected:
    int getEmpId() const {
        return empid;
    }
    string getSalaryStr() const {
        return salaryStr;
    }
    float getSal() const {
        return salary;
    }
};

class emplevel : public Employee {
public:
    // constructor calls base class constructor
    emplevel(int id, string sal) : Employee(id, sal) {}

    int getlevel() const {
        return (salary > 100) ? 1 : 2;
    }

    // public wrappers to access protected members
    int getId() const {
        return getEmpId();
    }
    string getSalStr() const {
        return getSalaryStr();
    }
    float getSalaryVal() const {
        return getSal();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; string s;
    cin >> n >> s;

    emplevel e(n, s);

    cout << e.getId() << "\n";
    cout << e.getSalStr() << "\n";
    cout << e.getlevel() << "\n";

    return 0;
}
