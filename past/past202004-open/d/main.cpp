#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

vector<string> t;
void dfs(string v) {
  if (v.size()) t.push_back(v);
  if (v.size() == 3) return;
  dfs(v+'.');
  REP(i,26) dfs(v + char('a'+i));
}

int main() {
  string s; cin >> s;
  dfs("");
  int ans = 0;
  for(auto v: t) ans += regex_search(s,regex(v));
  cout << ans << endl;
  return 0;
}