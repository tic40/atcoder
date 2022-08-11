#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int n;
bool dfs(int x, vector<int> m, int depth) {
  if (depth == min(3,n)) return x % 8 == 0;

  bool ok = false;
  REP(i,10) {
    if (m[i] == 0) continue;
    int nx = x * 10 + i;
    m[i]--;
    ok = ok || dfs(nx,m,depth+1);
    m[i]++;
  }
  return ok;
}

int main() {
  string s; cin >> s;
  n = s.size();
  vector<int> m(10);
  REP(i,n) m[s[i]-'0']++;

  cout << (dfs(0,m,0) ? "Yes" : "No") << endl;
  return 0;
}