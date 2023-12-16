#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<int> t(n),x(n);
  REP(i,n) {
    cin >> t[i] >> x[i];
    x[i]--;
  }

  vector g(n, vector<int>());
  vector<int> potion(n); // potion[i] := ポーションを i に拾ったら 1
  REP(i,n) {
    if (t[i] == 1) g[x[i]].push_back(i);
    if (t[i] == 2) {
      if (g[x[i]].size() == 0) { cout << -1 << endl; return 0; }
      potion[g[x[i]].back()] = 1;
      g[x[i]].pop_back();
    }
  }

  vector<int> ans;
  int mx = 0, sum = 0;
  REP(i,n) {
    if (t[i] == 1) {
      ans.push_back((potion[i] ? 1 : 0));
      if (potion[i]) { sum++; mx = max(mx,sum); }
    }
    if (t[i] == 2) sum--;
  }

  cout << mx << endl;
  for(auto v: ans) cout << v << " ";
  return 0;
}