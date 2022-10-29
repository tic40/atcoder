#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;
using mint = modint998244353;

int main() {
  ll a,b,c,d,e,f;
  cin >> a >> b >> c >> d >> e >> f;
  mint ans = (mint)a*b*c - (mint)d*e*f;
  cout << ans.val() << endl;

  return 0;
}