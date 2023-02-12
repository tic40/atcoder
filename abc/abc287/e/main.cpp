#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<pair<string,int>> s(n);
  REP(i,n) {
    cin >> s[i].first;
    s[i].second = i;
  }
  stable_sort(s.begin(),s.end());
  vector<int> ans(n);

  REP(i,n-1) {
    auto [a,ai] = s[i];
    auto [b,bi] = s[i+1];
    int now = 0;
    while (now < (int)a.size() && now < (int)b.size()) {
      if (a[now] != b[now]) break;
      now++;
    }
    ans[ai] = max(ans[ai],now);
    ans[bi] = max(ans[bi],now);
  }

  for(int v: ans) cout << v << endl;
  return 0;
}