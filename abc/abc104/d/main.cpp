#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

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

mint dp[100000][4];
/* memo
dp[ i + 1 ][ 0 ] := i 文字目まで考えたときに ABC との照合をスタートすらしていないようなものの個数
dp[ i + 1 ][ 1 ] := i 文字目まで考えたときに ABC との照合において A までは照合させたようなものの個数
dp[ i + 1 ][ 2 ] := i 文字目まで考えたときに ABC との照合において B までは照合させたようなものの個数
dp[ i + 1 ][ 3 ] := i 文字目まで考えたときに ABC との照合において C までは照合させたようなものの個数
*/

int main() {
  string s; cin >> s;
  int n = s.size();

  dp[0][0] = 1;
  REP(i,n) {
    REP(j,4) dp[i+1][j] += s[i]== '?' ? dp[i][j]*3 : dp[i][j];

    if (s[i] == 'A') dp[i+1][1] += dp[i][0];
    else if (s[i] == 'B') dp[i+1][2] += dp[i][1];
    else if (s[i] == 'C') dp[i+1][3] += dp[i][2];
    else if (s[i] == '?') {
      dp[i+1][1] += dp[i][0];
      dp[i+1][2] += dp[i][1];
      dp[i+1][3] += dp[i][2];
    }
  }

  cout << dp[n][3] << endl;
  return 0;
}