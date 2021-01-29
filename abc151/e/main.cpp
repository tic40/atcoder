#include <bits/stdc++.h>
using namespace std;
#define COUT(x) cout<<(x)<<"\n"
#define REP(i,n) for(int i=0;i<n;i++)
#define endl "\n"
using ll = long long;
const int MOD = 1e9+7;

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

int n,k;
vector<int> a;

const int MAX = 100005;
long long fac[MAX], finv[MAX], inv[MAX];
void COMinit() { // テーブルを作る前処理
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++){
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
  return;
}

long long COM(int n, int k) { // 二項係数計算
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

void solve() {
  COMinit();

  auto f = [&](){
    mint sum = 0;
    for (int i = k-1; i <= n; i++) {
      sum += mint(a[i]) * COM(i,k-1);
    }
    return sum;
  };

  sort(a.begin(), a.end());
  mint summax = f();
  reverse(a.begin(), a.end());
  mint summin = f();

  COUT(summax - summin);
  return;
}

int main() {
  cin >> n >> k;
  a.resize(n);
  REP(i,n) cin >> a[i];

  solve();
  return 0;
}