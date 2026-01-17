#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool openFileIn(fstream &, string);
void showContents(fstream &);

int main() {
    fstream dataFile;
    if (openFileIn(dataFile, "demofile.txt")) {
        cout << "File opened successfully." << endl;
        cout << "Reading data from file:" << endl;
        showContents(dataFile);
        dataFile.close();
        cout << endl << "Done." << endl;
    } else {
        cerr << "File open error!" << endl;
    }
    return 0;
}

bool openFileIn(fstream &file, string name) {
    file.open(name, ios::in);
    return !file.fail();
}

void showContents(fstream &file) {
    string line;
    while (file >> line) {
        cout << line << endl;
    }
}
