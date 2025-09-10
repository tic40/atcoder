#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,k; cin >> n >> k;
  vector<int> ans(1,k);
  REP(i,n) {
    vector<int> nx;
    for(int v: ans) {
      nx.push_back(v/2);
      nx.push_back(v-v/2);
    }
    swap(ans,nx);
  }

  int x = *max_element(ans.begin(),ans.end()) - *min_element(ans.begin(),ans.end());
  cout << x << endl;
  for(auto v: ans) cout << v << " ";
  return 0;
}
