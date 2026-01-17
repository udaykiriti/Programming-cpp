/*
  File Copy Utility
  Copies a file from source to destination
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool copy_file(const string& source, const string& dest) {
    ifstream src(source, ios::binary);
    if (!src) {
        cerr << "Error: Cannot open source file: " << source << endl;
        return false;
    }

    ofstream dst(dest, ios::binary);
    if (!dst) {
        cerr << "Error: Cannot open destination file: " << dest << endl;
        return false;
    }

    char buff[4096];
    while (src.read(buff, sizeof(buff)) || src.gcount() > 0) {
        dst.write(buff, src.gcount());
    }

    src.close();
    dst.close();
    cout << "Done! Copied " << source << " -> " << dest << endl;
    return true;
}

int main() {
    string source, dest;
    
    cout << "Enter source file path: ";
    getline(cin, source);
    
    cout << "Enter destination file path: ";
    getline(cin, dest);

    bool ok = copy_file(source, dest);
    cout << (ok ? "Completed" : "Something went wrong") << endl;
    
    return ok ? 0 : 1;
}