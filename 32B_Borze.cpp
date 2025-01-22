#include<bits/stdc++.h>

using namespace std;

int main() {
    string borze, decoded = "";
    cin >> borze;

    for (int i = 0; i < borze.length(); ) {
        if (borze[i] == '.') {
            decoded += '0';
            i++;
        } else if (borze[i] == '-' && i + 1 < borze.length() && borze[i + 1] == '.') {
            decoded += '1';
            i += 2;
        } else if (borze[i] == '-' && i + 1 < borze.length() && borze[i + 1] == '-') {
            decoded += '2';
            i += 2;
        }
    }

    cout << decoded << endl;
    return 0;
}