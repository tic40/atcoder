#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

int main() {
  vector<int> a(10);
  REP(i,10) cin >> a[i];
  int cur = 0;
  REP(i,3) cur = a[cur];
  cout << cur << endl;

  return 0;
}