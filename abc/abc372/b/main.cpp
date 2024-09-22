#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int m; cin >> m;
  vector<int> ans;
  for(int i = 0; m > 0; i++) {
    while(m%3 != 0) { m--; ans.push_back(i); }
    m /= 3;
  }
  cout << ans.size() << endl;
  for(auto v: ans) cout << v << " ";
}