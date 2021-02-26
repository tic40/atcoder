#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  string s,t;
  cin >> s >> t;
  int n = s.size();

  map<char,char> sm,gm;

  string ans = "Yes";
  REP(i,n) {
    if (sm[s[i]] || gm[t[i]]) {
      if (sm[s[i]] != t[i] || gm[t[i]] != s[i]) ans = "No";
    }
    sm[s[i]] = t[i];
    gm[t[i]] = s[i];
  }

  cout << ans << endl;
  return 0;
}