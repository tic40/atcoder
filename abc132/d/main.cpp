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

mint c[2005][2005];

// パスカルの三角形を前計算する
void init() {
  c[0][0] = 1;
  REP(i,2001) REP(j,i+1) {
    c[i+1][j] += c[i][j];
    c[i+1][j+1] += c[i][j];
  }
  return;
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
  init();
  int n, k; cin >> n >> k;

  for (int i = 1; i <= k; i++) {
    mint blue = f(k,i);
    mint red = 0;
    {
      red += f(n-k,i-1); // 両端を含まない
      red += f(n-k,i); // 片方の端を含む
      red += f(n-k,i); // 片方の端を含む
      red += f(n-k,i+1); // 両端を含む
    }
    mint ans = blue * red;
    cout << ans << endl;
  }
  return 0;
}