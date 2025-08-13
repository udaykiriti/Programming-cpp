#ifndef FINALEXAM_H
#define FINALEXAM_H
#include "GradeActivity.h"

class FinalExam:public GradeActivity
{
private:
    /* data */
    int numQuestions;
    double pointsEach;
    int numMissed;
public:
    FinalExam(/* args */){
        numQuestions=0;
        pointsEach=0;
        numMissed=0;
    }
    
};
#endif