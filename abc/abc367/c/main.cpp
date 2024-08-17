#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,k; cin >> n >> k;
  vector<int> r(n);
  REP(i,n) cin >> r[i];

  auto dfs = [&](auto self, vector<int> x) -> void {
    int i = x.size();
    if (i == n) {
      if (accumulate(x.begin(),x.end(),0) % k == 0) {
        for(auto v: x) cout << v << " ";
        cout << endl;
      }
      return;
    }

    for(int j = 1; j <= r[i]; j++) {
      x.push_back(j);
      self(self,x);
      x.pop_back();
    }
  };

  dfs(dfs,vector<int>());
  return 0;
}