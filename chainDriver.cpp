#include "chain.h"
using namespace std;

int main () {
    int testcount;
    cout << "Enter test count: ";
    cin >> testcount;

    chain c;

    for (int i = 0; i < testcount; i++) {
        c.append(i); // doesn't even require stuff from triple T!!!! I think!!!!!!
    }

    for (int i = 0; i < testcount; i++) {
        cout << c[i] << endl;
    }

    return 0;
}