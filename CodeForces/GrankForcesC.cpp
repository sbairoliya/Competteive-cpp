/*
 * Developed By : Shivam Bairoliya
 */

#include <iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<unordered_set>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<chrono>
#include<cmath>
#include<numeric>
#include <iomanip>

using namespace std;
using namespace chrono;

typedef unsigned long long ull;
typedef long double lld;
typedef long long ll;


#define vi vector<int>
#define vl vector<long long>
#define MOD 1000000007
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define readNumbersArray(n, arr) for(int i = 0; i < n; i++){cin>>arr[i];}
#define readNumbersArray1(n, arr) for(int i = 0; i < n; i++){cin>>arr[i + 1];}
#define modSum(a, b) (((a%MOD)+(b%MOD))%MOD)
#define modMultiply(a, b) (((a%MOD)*(b%MOD))%MOD)

/************************************* SOLUTION BELOW ***************************************/
void solve() {
    ll n, l;
    cin >> n >> l;
    ll array[n + 2];
    readNumbersArray1(n, array);
    array[0] = 0;
    array[n + 1] = l;
    vector<double> car1;
    car1.push_back(0);
    double currSpeed = 1.0;
    for (int i = 1; i <= n + 1; ++i) {
        double prevt = car1[i - 1];
        double currD = array[i] - array[i - 1];
        double extraT = currD / currSpeed;
        currSpeed += 1;
        car1.push_back(prevt + extraT);
    }
    ll newArray[n + 2];
    newArray[0] = 0;
    newArray[n + 1] = l;
    for (int i = 0; i <= n; ++i) {
        newArray[i + 1] = l - array[n - i];
    }
    vector<double> car2;
    car2.push_back(0);
    currSpeed = 1.0;
    for (int i = 1; i <= n + 1; ++i) {
        double prevt = car2[i - 1];
        double currD = newArray[i] - newArray[i - 1];
        double extraT = currD / currSpeed;
        currSpeed += 1;
        car2.push_back((prevt + extraT));
    }
    ll index1 = 0;
    ll index2 = 0;
    double car2pos = 0;
    double car1pos = 0;
    double currTime = 0;
    while (true) {
        double speed1 = index1 + 1;
        double speed2 = index2 + 1;
        double distance1;
        double distance2;
        if (currTime > car1[index1]) {
            double elapsed = currTime - car1[index1];
            distance1 = car1pos + (elapsed * speed1);
            distance2 = l - car2pos;
        } else {
            double elapsed = currTime - car2[index2];
            distance2 = l - (car2pos + (elapsed * speed2));
            distance1 = car1pos;
        }
        double time = (distance2 - distance1) / (speed1 + speed2) + currTime;
        if (time < car1[index1 + 1] && time < car2[index2 + 1]) {
            cout << setprecision(8) <<time << endl;
            break;
        } else {
            if (car1[index1 + 1] < car2[index2 + 1]) {
                index1++;
                car1pos = array[index1];
                currTime = car1[index1];
            } else if(car2[index2 + 1] < car1[index1 + 1]) {
                index2++;
                car2pos = newArray[index2];
                currTime = car2[index2];
            } else {
                index1++;
                index2++;
                currTime = car1[index1];
                car1pos = array[index1];
                car2pos = newArray[index2];
            }
        }
    }
}

int32_t main() {
    fastio();
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    freopen("../error.in", "w", stderr);
    auto start = high_resolution_clock::now();
#endif
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
#ifndef ONLINE_JUDGE
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken for execution: "
         << duration.count() << " ms" << endl;
#endif
}
