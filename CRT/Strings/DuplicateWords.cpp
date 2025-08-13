#include <iostream>
using namespace std;

int main() {
    string passage;
    getline(cin, passage);

    const int MAX_WORDS = 1000;
    string words[MAX_WORDS];
    int wordCount = 0;

    int start = 0, len = 0;
    for (int i = 0; ; i++) {
        char c = passage[i];
        if (c == ' ' || c == '\0') {
            if (len > 0) {
                string word = "";
                for (int j = start; j < start + len; j++) {
                    char ch = passage[j];
                    if (ch >= 'A' && ch <= 'Z') ch += 32;
                    word += ch;
                }
                words[wordCount++] = word;
            }
            if (c == '\0') break;
            start = i + 1;
            len = 0;
        } else {
            len++;
        }
    }

    bool printed[MAX_WORDS] = {false};
    cout << "Duplicate words:\n";
    bool found = false;
    for (int i = 0; i < wordCount; i++) {
        if (printed[i]) continue;
        int count = 1;
        for (int j = i + 1; j < wordCount; j++) {
            if (words[i] == words[j]) {
                count++;
                printed[j] = true;
            }
        }
        if (count > 1) {
            cout << words[i] << " (" << count << " times)" << endl;
            found = true;
        }
    }
    if (!found) cout << "No duplicate words found." << endl;

    return 0;
}
