#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using mint = modint;
int MOD;

vector<vector<ll>> mat_mul(vector<vector<ll>> a, vector<vector<ll>> b) {
  int n = a.size();
  vector res(n,vector<ll>(n));
  REP(i,n) REP(j,n) REP(k,n) {
    res[i][j] += a[i][k] * b[k][j];
    res[i][j] %= MOD; // MOD取る場合
  }
  return res;
}

/*
  a: 行列
  x: 何乗するか
*/
vector<vector<ll>> mat_pow(vector<vector<ll>> a, ll x) {
  if (x == 0) {
    int n = a.size();
    vector res(n,vector<ll>(n));
    REP(i,n) res[i][i] = 1;
    return res;
  }

  auto b = mat_pow(a,x/2);
  auto res = mat_mul(b,b);

  return x % 2 == 1 ? mat_mul(res,a) : res;
}

void solve1() {
  int a; ll x;
  cin >> a >> x >> MOD;
  vector<vector<ll>> f = { {a,1}, {0,1} };
  vector<vector<ll>> g = mat_pow(f,x);
  cout << g[0][1] << endl;
}

// 解説放送解
void solve2() {
  int a,m; ll x;
  cin >> a >> x >> m;
  mint::set_mod(m);

  auto f = [&](auto f, ll x) -> pair<mint,mint> {
    if (x == 0) return { 0, 1 };
    auto [s,p] = f(f,x/2);
    s += s*p;
    p *= p;
    if (x % 2 == 1) { s = s*a+1; p *= a; }
    return { s, p };
  };

  mint ans = f(f,x).first;
  cout << ans.val() << endl;
}

int main() {
  // solve1();
  solve2();
  return 0;
}
