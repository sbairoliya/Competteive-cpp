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


using namespace std;
using namespace chrono;

typedef unsigned long long ull;
typedef long double lld;
typedef long long ll;

#define int long long
#define vi vector<int>
#define vl vector<long long>
#define MOD 1000000007
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define readNumbersArray(n, arr) for(int i = 0; i < n; i++){cin>>arr[i];}
#define readNumbersArray1(n, arr) for(int i = 0; i < n; i++){cin>>arr[i + 1];}
#define modSum(a, b) (((a%MOD)+(b%MOD))%MOD)
#define modMultiply(a, b) (((a%MOD)*(b%MOD))%MOD)

/************************************* SOLUTION BELOW ***************************************/

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void LevelOrderCount(vector<int> adj[]) {

}


void solve() {
    ll n;
    cin >> n;
    vi adj[n + 1];
    for (int i = 1; i < n; ++i) {
        ll u, v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }
    string s;
    cin >> s;
    queue<ll> q;  // Create a queue
    q.push(1); // Enqueue root
    bool x = true;
    ll xcount = 0;
    ll ycount = 0;
    bool arrayVisited[n + 1];
    for (int i = 1; i <= n; ++i) {
        arrayVisited[i] = false;
    }
    while (!q.empty()) {
        int n = q.size();
        // If this node has children
        while (n > 0) {
            // Dequeue an item from queue and print it
            ll p = q.front();
            q.pop();
            arrayVisited[p] = true;
            x ? xcount++ : ycount++;
            // Enqueue all children of the dequeued item
            for (ll i: adj[p]) {
                if (!arrayVisited[i])
                    q.push(i);
            }
            n--;
        }
        x = !x;
    }
    ll array[n + 1];
    ll zeroCount = 0;
    ll oneCount = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '0') {
            zeroCount++;
            array[i] = 0;
        } else {
            oneCount++;
            array[i] = 1;
        }
    }
    if (!((oneCount == xcount && zeroCount == ycount) ||
          (oneCount == ycount && zeroCount == xcount))) {
        cout << -1 << endl;
        return;
    }
    ll currentNOde;
    if (oneCount == xcount) {
        currentNOde = 1;
    } else {
        currentNOde = 0;
    }
    ll mainCOunt = 0;
    q.push(1);
    for (int i = 1; i <= n; ++i) {
        arrayVisited[i] = false;
    }
    while (!q.empty()) {
        int n = q.size();
        // If this node has children
        while (n > 0) {
            // Dequeue an item from queue and print it
            ll p = q.front();
            q.pop();
            arrayVisited[p] = true;
            if (array[p] != currentNOde) {
                ll count = 0;
                queue<ll> tempqueue;  // Create a queue
                tempqueue.push(p);
                unordered_set<ll> visit;
                bool check = true;
                while (!tempqueue.empty() && check) {
                    int z = tempqueue.size();
                    while (z > 0) {
                        ll node = tempqueue.front();
                        visit.insert(node);
                        tempqueue.pop();
                        if (array[node] == currentNOde && count % 2 == 1) {
                            mainCOunt += count;
                            array[node] = !currentNOde;
                            array[p] = currentNOde;
                            check = false;
                            break;
                        }
                        for (ll i: adj[node]) {
                            if (visit.find(i) == visit.end())
                                tempqueue.push(i);
                        }
                        z--;
                    }
                    count++;
                }
            }
            // Enqueue all children of the dequeued item
            for (ll i: adj[p]) {
                if (!arrayVisited[i])
                    q.push(i);
            }
            n--;
        }
        currentNOde = !currentNOde;
    }
    cout << mainCOunt << endl;
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