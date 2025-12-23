#include <bits/stdc++.h>
using namespace std;
#include "ContactInfo.h"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ContactInfo entry("uday", "129-131");

    cout << entry.getName() << '\n';
    cout << entry.getPhone() << '\n';

    return 0;
}