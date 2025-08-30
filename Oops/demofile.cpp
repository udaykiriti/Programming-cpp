#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

bool openFileIn(fstream &,string);
void showContents(fstream &);

int main(){
    /*
    fstream dataFile;
    cout<<"opening File...."<<endl;
    dataFile.open("demofile.txt",ios::out);
    cout<<"============wrinting data into file================"<<endl;
    dataFile<<"h"<<endl;
    dataFile<<"e"<<endl;
    dataFile.close();
    cout<<"Done......"<<endl;
    
    cout<<"opening File again...."<<endl;
    dataFile.open("demofile.txt",ios::out|ios::app);
    cout<<"============wrinting data into file================"<<endl;
    dataFile<<"l"<<endl;
    dataFile<<"l"<<endl;
    dataFile<<"0.."<<endl;
    cout<<"Closing again...."<<endl;
    dataFile.close();
    cout<<"Done......"<<endl;
    */
   /*
   const int r=3;
   const int c=3;
   int nums[r][c]={ 2897, 5, 837,34, 7, 1623,390, 3456, 12 };
   fstream outFile("table.txt",ios::out);
   for (int i = 0; i < r; i++){
    for (int j = 0; j < c; j++){
        outFile<<setw(8)<<nums[r][c];
    }
    outFile<<endl;
    }
    outFile.close();
    cout<<"Done."<<endl;
    return 0;
    */
   fstream dataFile;
   if(openFileIn(dataFile,"demofile.txt")){
    cout<<"file opened successfully"<<endl;
    cout<<"Now reading data from file......."<<endl;
    showContents(dataFile);
    dataFile.close();
    cout<<endl<<"done"<<endl;
   }else{
    cerr<<"file open error!!!"<<endl;
   }return 0;
}
bool openFileIn(fstream &file,string name){
    file.open(name,ios::in);
    if(file.fail())
        return false;
    else
        return true;
    
}
void showContents(fstream &file){
    string line;
    while(file>>line){
        cout<<line<<endl;
    }
}