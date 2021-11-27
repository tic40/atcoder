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
  vector<string> s(2);
  REP(i,2) cin >> s[i];
  int ok = false;
  if (s[0][0] == '#' && s[0][1] == '#') ok = true;
  if (s[1][0] == '#' && s[1][1] == '#') ok = true;
  if (s[0][0] == '#' && s[1][0] == '#') ok = true;
  if (s[0][1] == '#' && s[1][1] == '#') ok = true;

  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}