#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
const int INF = numeric_limits<int>::max();

int main() {
  int n; cin >> n;
  vector<int> s(n),t(n);
  REP(i,n) cin >> s[i];
  REP(i,n) cin >> t[i];
  REP(i,n) {
    s.push_back(s[i]);
    t.push_back(t[i]);
  }
  int n2 = n*2;

  int now = INF;
  vector<int> ans(n,INF);
  REP(i,n2) {
    now = min(now,t[i]);
    ans[i%n] = min(ans[i%n],now);
    now += s[i];
  }
  REP(i,n) cout << ans[i] << endl;
  return 0;
}