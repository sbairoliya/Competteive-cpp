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

/**
 * @class UF describes a Union Find Data Structure
 */

class UF {
    vl parent, size;
    ll count = 0;

public:

    /**
     * Constructor which initializes the data structure
     * @param n - the size of the data structure
     */
    UF(ll n) {
        count = n;
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (ll i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    /**
     * The function returns the ultimate parent of the node while also
     * making all the elements in the route point to the ultimate parent
     * @param p - the node whose parent needs to br found
     * @return the set i.e. the parent to which the node belongs to
     */
    ll find(ll p) {
        if (p == parent[p]) {
            return p;
        }
        parent[p] = find(parent[p]);
        return parent[p];
    }

    /**
     * The function merges two sets and sets their parents to the same
     * value if they are in different sets
     * @param p - set to be merged
     * @param q - set to be merged
     * @return bool - true if sets are different false if sets are same
     */
    bool pUnion( ll p, ll q) {
        ll a = find(p), b = find(q);
        if (a == b) {
            return false;
        }
        count--;
        if (size[a] <= size[b]) {
            parent[a] = b;
            size[b] += size[a];
            return true;
        } else {
            parent[b] = a;
            size[a] += size[b];
            return true;
        }
    }

    /**
     * Getter for the number of components
     * @return the number of components
     */
    ll getCount() {
        return count;
    }
};

/**
 * Returns the gcd of the two parameters
 */

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

/**
 * Return x^y % p
 * @param x
 * @param y is MOD - 2 if we want inverse
 * @param p MOD
 * @return
 */

ll power(ll x, ll y = MOD - 2, ll p = MOD) {
    ll res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

/**
 * returns the modular sum of x and y
 */

ll modSum(ll x, ll y, ll p = MOD) {
    return ((x % MOD) + (y % MOD)) % MOD;
}

/**
 * returns the modular product of x and y
 */

ll modMultiply(ll x, ll y, ll p = MOD) {
    return ((x % MOD) * (y % MOD)) % MOD;
}

