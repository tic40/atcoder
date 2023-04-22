#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n,t; cin >> n >> t;
  vector<int> c(n),r(n);
  REP(i,n) cin >> c[i];
  REP(i,n) cin >> r[i];

  map<int,vector<P>> mp;
  REP(i,n) mp[c[i]].push_back({ r[i], i });

  int col =  mp[t].size() ? t : c[0];
  sort(mp[col].begin(), mp[col].end());
  cout << mp[col].back().second+1 << endl;
  return 0;
}