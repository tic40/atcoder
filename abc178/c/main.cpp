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

const int mod = 1e9+7;
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

mint choose(int n, int a) {
  mint x = 1, y = 1;
  REP(i,a) {
    x *= n-i;
    y *= i+1;
  }
  return x / y;
}

mint f(int n, int a) {
  if (n == 0) return 1;
  mint x = f(n/2, a);
  x *= x;
  if (n % 2 == 1) x *= a;
  return x;
}

int main() {
  IOS;
  int n; cin >> n;

  mint p1 = f(n, 10); // 全通り
  mint p2 = f(n, 9) * 2; // 0が存在しないケース/9が存在しないケース
  mint p3 = f(n, 8); // 0と9が共に存在しないケース

  // 包除原理
  // (0が存在しないケース + 9が存在しないケースから) 0と9が共に存在しないケースを
  // 引くことで、0または9が少なくとも一方が存在しないケースとなる。
  // 全体から、0または9が少なくとも一方が存在しないケースを引けば、
  // 0と9が両方存在するケースとなる
  COUT( p1 - (p2 - p3) );
  return 0;
}