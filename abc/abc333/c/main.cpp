#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<ll> x = { 1 };
  REP(i,11) x.push_back(x.back()*10+1);

  set<ll> st;
  auto dfs = [&](auto self, ll tot, int cnt) -> void {
    if (cnt == 3) { st.insert(tot); return; }
    for(auto v: x) { self(self,tot+v,cnt+1); }
  };

  dfs(dfs,0,0);
  auto it = st.begin();
  REP(i,n-1) it++;
  cout << *it << endl;
  return 0;
}