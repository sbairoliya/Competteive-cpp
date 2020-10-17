#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

typedef unsigned long long ull;
typedef long double lld;
typedef long long ll;

#define vi vector<int>
#define vl vector<long long>
#define MOD 1000000007


/**
 * This is a pair comparator which compares by the first element
 * and then by the second element
 * @param a - the first pair
 * @param b - the second pair
 * @return bool
 */
bool comparePairs(pair<ll, ll> a, pair<ll, ll> b) {
    if (a.first == b.first) {
        return a.second >= b.second;
    }
    return a.first > b.first;
}
/**
 * This is a pair comparator which compares by the first element
 * and then by the second element
 * @param a - the first pair
 * @param b - the second pair
 * @return bool
 */
bool comparePairsSecond(pair<ll, ll> a, pair<ll, ll> b) {
    if (a.second == b.second) {
        return a.first >= b.first;
    }
    return a.second > b.second;
}


