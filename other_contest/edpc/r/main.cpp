#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;
const int INF = numeric_limits<int>::max();
const int MOD = 1e9+7;
using mint = modint1000000007;

vector<vector<ll>> matrixmul(vector<vector<ll>> a, vector<vector<ll>> b) {
  int n = a.size();
  vector res(n,vector<ll>(n));
  REP(i,n) REP(j,n) REP(k,n) {
    res[i][j] += a[i][k] * b[k][j];
    res[i][j] %= MOD; // MOD取る場合
  }
  return res;
}

vector<vector<ll>> matrixpow(vector<vector<ll>> a, ll x) {
  if (x == 0) {
    int n = a.size();
    vector res(n,vector<ll>(n));
    REP(i,n) res[i][i] = 1;
    return res;
  }

  auto b = matrixpow(a,x/2);
  auto res = matrixmul(b,b);

  return x % 2 == 1 ? matrixmul(res,a) : res;
}

int main() {
  int n; ll k;
  cin >> n >> k;
  vector a(n,vector<ll>(n));
  REP(i,n) REP(j,n) cin >> a[i][j];

  mint ans = 0;
  auto b = matrixpow(a,k);
  REP(i,n) REP(j,n) ans += b[i][j];

  cout << ans.val() << endl;
  return 0;
}