#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<string> ans;

  // cnt := 閉じていない開き括弧の数
  auto dfs = [&](auto self, string s, int cnt) {
    if ((int)s.size() == n) {
      if (cnt == 0) ans.push_back(s);
      return;
    }
    self(self, s+"(", cnt+1);
    if (cnt > 0) self(self, s+")", cnt-1);
  };

  dfs(dfs,"(",1);
  sort(ans.begin(),ans.end());
  for(auto v: ans) cout << v << endl;
  return 0;
}