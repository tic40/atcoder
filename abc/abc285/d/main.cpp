#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  map<string,vector<string>> mp;
  map<string,int> deg;
  unordered_set<string> st;
  REP(i,n) {
    string s,t; cin >> s >> t;
    st.insert(s);
    st.insert(t);
    mp[s].push_back(t);
    deg[t]++;
  }

  queue<string> q;
  for(string v: st) if (deg[v] == 0) q.push(v);

  int ans = 0;
  while(q.size()) {
    auto v = q.front(); q.pop();
    ans++;
    for(auto nv: mp[v]) {
      deg[nv]--;
      if (deg[nv] == 0) q.push(nv);
    }
  }

  bool ok = ans == (int)st.size();
  cout << (ok ? "Yes" : "No") << endl;

  return 0;
}