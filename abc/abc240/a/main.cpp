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
  int a,b;
  cin >> a >> b;

  int d = abs(a-b);
  bool ok = d == 1 || d == 9;
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}