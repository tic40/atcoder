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
  string s,t;
  cin >> s >> t;
  int n = s.size();
  int p = -1;
  REP(i,n) {
    int d = t[i]-s[i];
    if (d < 0) d += 26;
    if (p == -1 || p == d) {
      p = d;
      continue;
    }
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;
  return 0;
}