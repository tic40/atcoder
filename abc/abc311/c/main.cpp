#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> g(n);
  REP(i,n) {
    int a; cin >> a; a--;
    g[i] = a;
  }

  int v = 0;
  REP(i,n) v = g[v];

  int start = v;
  vector<int> ans;
  do {
    ans.push_back(v);
    v = g[v];
  } while(v != start);

  cout << ans.size() << endl;
  for(auto x: ans) cout << x+1 << " ";
  return 0;
}