#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  string s; cin >> s;

  bool ok = regex_match(s,regex("(dream|dreamer|erase|eraser)+"));
  cout << (ok ? "YES" : "NO") << endl;
  return 0;
}