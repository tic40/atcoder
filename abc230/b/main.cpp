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
  string s;
  cin >> s;
  string t;
  REP(i,10) t += "oxx";
  cout << (regex_search(t,regex(s)) ? "Yes" : "No") << endl;

  return 0;
}