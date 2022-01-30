#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;

int main() {
  ll n;
  cin >> n;
  bool ok = (-(1LL<<31) <= n && n < (1LL<<31));
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}