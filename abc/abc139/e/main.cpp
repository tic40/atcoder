#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n; cin >> n;
  vector<queue<int>> q(n);
  REP(i,n) REP(j,n-1) {
    int a; cin >> a; a--;
    q[i].push(a);
  }

  set<P> st;
  REP(i,n) {
    int to = q[i].front();
    if (q[to].front() == i) st.emplace(min(i,to),max(i,to));
  }

  int ans = 0;
  while(st.size()) {
    set<P> old; swap(st,old);
    for(auto [a,b]: old) REP(_,2) {
      q[a].pop();
      int na = q[a].front();
      if (q[na].size() && q[na].front() == a) st.emplace(min(a,na),max(a,na));
      swap(a,b);
    }
    ans++;
  }

  REP(i,n) if (q[i].size()) ans = -1;
  cout << ans << endl;
  return 0;
}