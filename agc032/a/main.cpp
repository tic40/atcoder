#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
const int INF = 1e9;

int n;
vector<int> b;

void solve() {
  vector<int> ans;

  while(b.size()) {
    int ok = false;
    for(int j = b.size()-1; j >= 0; j--) {
      if (b[j] == j+1) {
        ans.push_back(b[j]);
        b.erase(b.begin() + j);
        ok = true;
        break;
      }
    }
    if (!ok) {
      cout << -1 << endl;
      return;
    }
  }

  reverse(ans.begin(), ans.end());
  for(int v: ans) cout << v << endl;

  return;
}

int main() {
  cin >> n;
  b.resize(n);
  REP(i,n) cin >> b[i];

  solve();
  return 0;
}