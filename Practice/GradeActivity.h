#ifndef GRADEACTIVITY_H
#define GRADEACTIVITY_H

class GradeActivity
{
private:
    double score;
public:
    GradeActivity(/* args */){
        score=0;
    }
    GradeActivity(double s){
        score=s;
    }
    void setscore(double s){
        score=s;
    }
    double getscore() const{
        return score;
    }
    char getLetterGrade() const;
};

char GradeActivity::getLetterGrade() const{
   char letterGrade;
   if (score > 89) letterGrade = 'A';
   else if (score > 79) letterGrade = 'B';
   else if (score > 69) letterGrade = 'C';
   else if (score > 59) letterGrade = 'D';
   else letterGrade = 'F'; 
   return letterGrade;
}
#endif