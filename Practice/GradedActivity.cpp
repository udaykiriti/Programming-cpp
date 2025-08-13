#include<bits/stdc++.h>
using namespace std;
#include "GradeActivity.h"

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    GradeActivity test;
    cout<<"Enter your test score: "<<flush;
    double testscore;  cin>>testscore;
    test.setscore(testscore);
    cout<<"letter grade foe numeric value : "<<test.getLetterGrade()<<endl;
}