#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n; cin >> n;
  vector<P> pa(n);
  unordered_map<int,int> mp;
  REP(i,n) {
    int a; cin >> a; pa[i] = {a,i};
    mp[a]++;
  }
  sort(pa.rbegin(),pa.rend());
  for(auto [v,i]: pa) if (mp[v] == 1) { cout << i+1 << endl; return 0; }
  cout << -1 << endl;
  return 0;
}
