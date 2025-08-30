#ifndef TREE_H
#define TREE_H

class Tree
{
private:
    static int objc;
public:
    Tree(/* args */){
        objc++;
    }
    int getObjCount() const{
        return objc;
    }
};
#endif

int Tree::objc=0;