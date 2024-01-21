#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) { cin >> a[i]; a[i]--; }

  map<int,int> mp;
  REP(i,n) mp[a[i]] = i;

  int now = -2;
  vector<int> ans;
  while(mp.count(now)) {
    now = mp[now];
    ans.push_back(now);
  }
  for(auto v: ans) cout << v+1 << " ";
  return 0;
}