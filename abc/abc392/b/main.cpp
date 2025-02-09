#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector<int> b(1000);
  REP(i,m) {
    int a; cin >> a; a--;
    b[a] = 1;
  }
  vector<int> ans;
  REP(i,n) if (b[i] == 0) ans.push_back(i+1);
  cout << ans.size() << endl;
  for(auto v: ans) cout << v << " ";
  return 0;
}
