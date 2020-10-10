/*
* Developed By: Shivam Bairoliya
* Created On: 10/9/2020 on 4:17 PM
*/

#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll arrayBharat[1001];
ll arrayShivam[1001];

int main() {
    arrayBharat[3] = 1;
    arrayShivam[3] = 1;
    for (int i = 4; i <= 100; ++i) {
        arrayShivam[i] = ((ll)(pow(2, i - 2)) * (i - 2)) - (ll)(pow(2, i - 3));
        arrayBharat[i] = (2 * arrayBharat[i - 1]) + (ll)(pow(2, i - 2));
    }
    cout << "i\tShivam\t\tBharat" << endl;
    for (int i = 3; i <= 100; ++i) {
        cout << i << "\t" << arrayShivam[i] << "\t" << arrayBharat[i] << endl;
    }
}