#ifndef TREE_H
#define TREE_H

class Tree {
private:
    static int objc;
public:
    Tree() {
        objc++;
    }
    int getObjCount() const {
        return objc;
    }
};

#endif
