#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int n;
set<string> st;

bool possible(string s) {
  int cnt = 0;
  for (char c: s) {
    c == '(' ? cnt++ : cnt--;
    if (cnt < 0) break;
  }
  return cnt == 0;
}

void dfs(string s = "") {
  if (s.size() == n) {
    if (possible(s)) st.insert(s);
    return;
  }

  dfs(s+"("); dfs(s+")");
}

int main() {
  cin >> n;
  dfs();
  for(string v: st) cout << v << endl;

  return 0;
}