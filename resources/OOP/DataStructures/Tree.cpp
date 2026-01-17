#include <iostream>
#include "Tree.h"
using namespace std;

// Initialize static member
int Tree::objc = 0;

int main() {
    Tree a;
    Tree b;
    Tree C;
    cout << "Object count: " << C.getObjCount() << endl;
    return 0;
}
