#include <bits/stdc++.h> 

#define NDEBUG
#define TERRORIST

#ifdef TERRORIST
using namespace std;
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


using pii = pair<int,int>;
using pil = pair<int,int64_t>;
using pli = pair<int64_t,int>;
using pll = pair<int64_t,int64_t>;
#define M_PI 3.14159265358979323846
#define allr(x) x.rbegin(), x.rend()
#define emp_back emplace_back
#define bitcount(x) __builtin_popcount((x))
#define mbin(val, cap) bitset<64>(val).to_string().substr(64 - cap)
#ifdef NDEBUG
    #define print(x) cout << "[ " << #x << " ]: " << x << "\n";
    #define e_ cout << "\n";
#else
    #define print(x)
    #define e_
#endif

template<typename T> ostream& operator<<(ostream &cout, vector<T> const &v);
template<typename F, typename S> ostream& operator<<(ostream &cout, pair<F, S> const &p) { return cout << "(" << p.first << ", " << p.second << ")"; }
template<typename T> ostream& operator<<(ostream &cout, vector<T> const &v) {
    cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}
template <typename K, typename V> ostream& operator<<(ostream& cout, const map<K, V>& omp) {
    for(auto& [k, v] : omp){ cout << "(" << k << ": " << v << ")"; if(&v != &omp.rbegin()->second) cout << ", ";} return cout;
}
template <typename T> ostream& operator<<(ostream& cout, const set<T>& ost){
    cout << "{"; for(auto& v : ost){ cout << v; if(v != *ost.rbegin()) cout << ", "; } cout << "}"; return cout;
}

mt19937_64 _GEN(chrono::high_resolution_clock::now().time_since_epoch().count());
template <typename T>
T mrand(T begin, T end) {
    if constexpr (is_integral<T>::value){ uniform_int_distribution<T> _UNI_DIST(begin, end); return _UNI_DIST(_GEN); } 
    else if constexpr (is_floating_point<T>::value) { uniform_real_distribution<T> _UNI_DIST(begin, end); return _UNI_DIST(_GEN); }
}
int fastIO = []{ ios_base::sync_with_stdio(false); cin.tie(NULL); return 0; }();
//down0, right1, up2, left3, upleft4, downright5, upright6, downleft7, stay8
constexpr int dx[9] = {0, 1, 0, -1, -1, 1, 1, -1, 0};
constexpr int dy[9] = {1, 0, -1, 0, -1, 1, -1, 1, 0};
#endif

template <uint64_t mod = 1'000'000'007>
struct Mint {
    uint64_t val;
    Mint() : val(0) {}
    Mint(int64_t _val) {
        _val %= mod;
        if (_val < 0) _val += mod;
        val = _val;
    }
    Mint& operator += (const Mint& other){ val += other.val; if(val >= mod) val -= mod; return *this; }
    Mint& operator -= (const Mint& other){ val += mod - other.val; if(val >= mod) val -= mod; return *this; }
    Mint& operator *= (const Mint& other){ val = (uint64_t)val * other.val % mod; return *this; }
    Mint& operator /= (const Mint& other){ return *this *= other.inv(); }
    Mint operator + (const Mint& other) const { return Mint(*this) += other; }
    Mint operator - (const Mint& other) const { return Mint(*this) -= other; }
    Mint operator * (const Mint& other) const { return Mint(*this) *= other; }
    Mint operator / (const Mint& other) const { return Mint(*this) /= other; }
    Mint pwr(int64_t expo) const {
        Mint res = 1;
        Mint cur = *this;
        while(expo){
            if(expo & 1) res *= cur;
            cur *= cur; expo >>= 1;
        }
        return res;
    }
    Mint inv() const { return pwr(mod - 2); }
    friend ostream& operator << (ostream& os, const Mint& m) { os << m.val; return os; }
    bool operator == (const Mint& other) const { return val == other.val; }
};

const uint64_t MOD = 1'000'000'007; // 8191 // 1e9 + 7 //1'000'000'000'039
using mint = Mint<MOD>;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
const int nax = 1'000'01;
int mdata[nax][3];

class Solution {
    public:
    
};

// #define MAIN_ACTIVE
#ifdef MAIN_ACTIVE
int main() {

    ifstream in("input.txt");
    ofstream out("output.txt", ios::trunc);
    out.close();
    out.open("output.txt", ios::app);
    Timer timer;
    
    return EXIT_SUCCESS;
}
#endif