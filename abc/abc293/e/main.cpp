#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
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

int main() {
  int a; ll x;
  cin >> a >> x >> MOD;
  vector<vector<ll>> f = { {a,1}, {0,1} };
  vector<vector<ll>> g = mat_pow(f,x);
  cout << g[0][1] << endl;
}