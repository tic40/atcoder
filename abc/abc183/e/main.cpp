#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
typedef long long ll;

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

const int MX = 2005;
int h,w;
char s[MX][MX];
mint dp[MX][MX], x[MX][MX], y[MX][MX], z[MX][MX]; // x: 右方向, y: 下方向, z: 右下方向

void f(int i, int j) {
  if (s[i][j] == '#') return;

  if (0 <= j-1) x[i][j] = x[i][j-1] + dp[i][j-1];
  if (0 <= i-1) y[i][j] = y[i-1][j] + dp[i-1][j];
  if (0 <= i-1 && 0 <= j-1) z[i][j] = z[i-1][j-1] + dp[i-1][j-1];

  dp[i][j] = x[i][j] + y[i][j] + z[i][j];
}

int main() {
  cin >> h >> w;
  REP(i,h) REP(j,w) cin >> s[i][j];

  dp[0][0] = 1;
  REP(i,h) REP(j,w) {
    if(i == 0 && j == 0) continue;
    f(i,j);
  }

  cout << dp[h-1][w-1] << endl;
  return 0;
}