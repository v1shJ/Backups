#include <bits/stdc++.h>
using namespace std;

// Typedefs and macros to save typing time
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<pii> vpii;

#define for(i,n) for(int i=0;i<n;i++) 
#define F first
#define S second
#define pb push_back
#define MP make_pair
#define all(x) x.begin(), x.end()

// Fast input-output
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// Constants
const int INF = 1e9;
const ll MOD = 1e9+7;
const ll LLINF = 1e18;

// Utility functions
ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

ll mod_pow(ll base, ll exp, ll mod = MOD) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

void solve(){
    
}


int main() {
    fastio;
    int t;
    cin >> t; 
    while (t--) {
        solve();
    }
    return 0;
}