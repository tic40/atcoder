#include <bits/stdc++.h>
using namespace std;
#define ALL(x) (x).begin(),(x).end()
#define COUT(x) cout<<(x)<<"\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define REP(i, n) for(int i=0;i<n;i++)
#define YES(x) cout<<(x?"YES":"NO")<<"\n"
#define Yes(x) cout<<(x?"Yes":"No")<<"\n"
#define dump(x) cout<<#x<<" = "<<(x)<<"\n"
#define endl "\n"
using G = vector<vector<int>>;
using M = map<int,int>;
using P = pair<int,int>;
using PQ = priority_queue<int>;
using PQG = priority_queue<int,vector<int>,greater<int>>;
using V = vector<int>;
using ll = long long;
using edge = struct { int to; int cost; };
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int INF = 1e9;
const ll LINF = 1e18;

const int mod = 1000000007;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

// パスカルの三角形
mint c[4005][4005];

// パスカルの三角形を前計算する
void init() {
  c[0][0] = 1;
  REP(i,4001) REP(j,i+1) {
    c[i+1][j] += c[i][j];
    c[i+1][j+1] += c[i][j];
  }
}

mint comb(int n, int k) {
  return c[n][k];
}

mint f2(int n, int k) {
  return comb(n+k-1,k-1);
}

// n個の中から、k個選ぶ
mint f(int n, int k) {
  if (n < k) return 0;
  if (n == 0 && k == 0) return 1;
  if (k < 1) return 0;
  return f2(n-k,k);
}

int main() {
  IOS;
  init();
  int n, k; cin >> n >> k;

  for (int i = 1; i <= k; i++) {
    mint blue = f(k,i);
    mint red = f2(n-k-(i-1), i+1);
    /* 場合わけする場合
    mint red = 0;
    {
      red += f(n-k,i-1); // 両端を含まない
      red += f(n-k,i); // 片方の端を含む
      red += f(n-k,i); // 片方の端を含む
      red += f(n-k,i+1); // 両端を含む
    }
    */
    mint ans = blue * red;
    COUT(ans);
  }
  return 0;
}
