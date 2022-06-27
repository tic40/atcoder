#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  map<int,int> mp;
  for(int v: a) mp[v]++;

  int cnt = 0;
  for(auto v: mp) {
    if (v.second == 2 || v.second % 2 == 0) cnt++;
  }

  int ans = mp.size() - cnt%2;
  cout << ans << endl;
  return 0;
}