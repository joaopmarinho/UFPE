#include <iostream>

using namespace std;

int main() {
    int n;
    string palavra[30], padrao[30];

    scanf("%d", &n);
    for (int i = 0; i < n; i++) cin >> palavra[i];

    for (int i = 0; i < n; i++) {
        cin >> padrao[i];
        if (padrao[i] == "#X") {
            for (int j = 0; j < 10; j++) {
                cout << j << palavra[0] << endl;
                cout << j << palavra[1] << endl;
            }
        
        } else {
            for (int j = 0; j < 10; j++) {
                cout << palavra[0] << j << endl;
            }
            for (int j = 0; j < 10; j++) {
                cout << palavra[1] << j << endl;
            }
        }
    }
}