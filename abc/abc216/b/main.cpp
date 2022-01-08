#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  int n; cin >> n;
  map<pair<string,string>, int> mp;
  bool ok = false;
  REP(i,n) {
    string s,t;
    cin >> s >> t;
    pair<string,string> p = {s,t};
    mp[p]++;
    if (mp[p] == 2) ok = true;
  }

  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}