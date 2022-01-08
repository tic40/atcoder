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
  int l,r; cin >> l >> r;
  string s; cin >> s;
  string fs = s.substr(0,l-1);
  string ms = s.substr(l-1,r-l+1);
  string ls = s.substr(r);
  reverse(ms.begin(),ms.end());
  cout << fs+ms+ls << endl;

  return 0;
}