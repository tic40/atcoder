#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<string> s(n),t(n);
  REP(i,n) cin >> s[i];
  REP(i,n) cin >> t[i];

  auto solve = [&](vector<string>& s, vector<string>& t) {
    int res = 0;
    REP(i,n) REP(j,n) if (s[i][j] != t[i][j]) res++;
    return res;
  };

  int ans = solve(s,t);
  REP(i,3) {
    auto ns = s;
    REP(i,n) REP(j,n) ns[i][j] = s[n-1-j][i];
    ans = min(ans,solve(ns,t)+(i+1));
    swap(s,ns);
  }
  cout << ans << endl;
  return 0;
}