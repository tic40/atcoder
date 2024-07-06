#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<string,int>;

int main() {
  int n; cin >> n;
  string s,t; cin >> s >> t;
  s += ".."; t += "..";
  n += 2;

  queue<P> q;
  q.emplace(s,0);
  unordered_set<string> st;

  int ans = -1;
  while(q.size()) {
    auto [now,cnt] = q.front(); q.pop();
    if (st.find(now) != st.end()) continue;
    st.insert(now);
    if (now == t) { ans = cnt; break; }

    int idx = 0;
    REP(i,n) if (now[i] == '.') { idx = i; break; }
    REP(i,n-1) if (now[i] != '.' && now[i+1] != '.') {
      swap(now[i],now[idx]);
      swap(now[i+1],now[idx+1]);
      q.emplace(now,cnt+1);
      swap(now[idx],now[i]);
      swap(now[idx+1],now[i+1]);
    }
  }

  cout << ans << endl;
  return 0;
}