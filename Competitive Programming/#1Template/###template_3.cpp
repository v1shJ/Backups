#include <iostream>
#include <bits/stdc++.h>
//#include <sys/resource.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace chrono;
//using namespace __gnu_pbds;

//Definitions
//#define gucci 1

//Speed
#define guccibanana ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//Aliases
using ll = long long;
using lld = long double;
using ull = unsigned long long;

//Constants
const lld pi = 3.141592653589;
const ll INF = LONG_LONG_MAX;
const ll mod = 1e9+7;

//TypeDefs
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<string> vs;

//Macros
#define vt vector
#define pb push_back
#define umap unordered_map
#define uset unordered_set
#define ll long long

//#define map ordered_map __nah who even uses this__
#define all(c) (c).begin(), (c).end()
#define rev(v) (v).end(), (v).begin()
#define sz(x) (int)(x).size()
#define fl(i, n) for(int i = 0; i < n; i++) //forward loop
#define rl(i, m, n) for(int i = n; i >= m; i--) //reverse loop
#define py cout << "YES\n";
#define pn cout << "NO\n";
#define pm cout << "-1\n";

// Operator Overloading
template<typename T1, typename T2> // cin >> pair<T1, T2>
istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v){for (auto &it : v)cin >> it;return istream;}
template<typename T1, typename T2> // cout << pair<T1, T2>
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }

// Utility functions
template <typename T>
void print(T &&t)  { cout << t << "\n"; }
void printarr(ll arr[], ll n){fl(i,n) cout << arr[i] << " ";cout << "\n";}
template<typename T>
void printvec(vector<T>v){ll n=v.size();fl(i,n)cout<<v[i]<<" ";cout<<"\n";}
template<typename T>
ll sumvec(vector<T>v){ll n=v.size();ll s=0;fl(i,n)s+=v[i];return s;}

// Mathematical functions
ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);} //__gcd doesn't normally handle cases for 0
ll lcm(ll a, ll b){return (a/gcd(a,b)*b);}
ll moduloMultiplication(ll a,ll b,ll mod){ll res = 0;a %= mod;while (b){if (b & 1)res = (res + a) % mod;b >>= 1;}return res;}
ll powermod(ll x, ll y, ll p){ll res = 1;x = x % p;if (x == 0) return 0;while (y > 0){if (y & 1)res = (res*x) % p;y = y>>1;x = (x*x) % p;}return res;}

//Check
bool isPrime(ll n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(int i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
bool isPowerOfTwo(int n){if(n==0)return false;return (ceil(log2(n)) == floor(log2(n)));}
bool isPerfectSquare(ll x){if (x >= 0) {ll sr = sqrt(x);return (sr * sr == x);}return false;}


//Code Func
void guccib(){
    ll n;
    cin >> n;
}

//Main
int main(){
    guccibanana
    ll t;
    cin >> t;
    fl(i, t){
        guccib();
    }
}