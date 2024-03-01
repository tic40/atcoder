#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,q; cin >> n >> q;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  map<int,vector<int>> mp;
  REP(i,n) mp[a[i]].push_back(i+1);
  REP(_,q) {
    int x,k; cin >> x >> k;
    if (!mp.count(x) || (int)mp[x].size() < k) cout << -1 << endl;
    else cout << mp[x][k-1] << endl;
  }
  return 0;
}