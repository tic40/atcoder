#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  string s,t; cin >> s >> t;

  queue<int> q;
  vector<bool> checked(n);
  auto push = [&](int i) -> void {
    if (checked[i]) return;
    REP(j,m) if (s[i+j] != t[j] && s[i+j] != '#') return;

    REP(j,m) s[i+j] = '#';
    checked[i] = true;
    q.push(i);
  };

  REP(i,n-m+1) push(i);
  while(q.size()) {
    auto v = q.front(); q.pop();
    for(int j = max(0,v-m+1); j < min(n,v+m); j++) push(j);
  }

  cout << (s == string(n,'#') ? "Yes" : "No") << endl;
  return 0;
}