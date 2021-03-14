#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%MOD+MOD)%MOD){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= MOD) x -= MOD;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += MOD-a.x) >= MOD) x -= MOD;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= MOD; return *this;}
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
  // for prime MOD
  mint inv() const { return pow(MOD-2);}
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

int main() {
  int x,y;
  cin >> x >> y;

  // 1ni, 2ni
  // 2nj, 1nj
  // ni + 2nj = x
  // 2ni + nj = y
  //  2nj = x-ni
  //  nj = y - 2ni
  mint ans = 0;
  REP(b, 1e6+1) {
    int a = x - 2*b;
    if (a < 0) break;
    if (y == 2*a + b) {
      ans += choose(a+b, b);
    }
  }
  cout << ans << endl;

  return 0;
}