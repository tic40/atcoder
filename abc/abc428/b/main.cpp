#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,string>;

int main() {
  int n,k; cin >> n >> k;
  string s; cin >> s;

  map<string,int> mp;
  REP(i,n-k+1) mp[s.substr(i,k)]++;
  int maxcnt = 0;
  for(auto [_,cnt]: mp) maxcnt = max(maxcnt,cnt);
  vector<string> ans;
  for(auto [k,cnt]: mp) if (cnt == maxcnt) ans.push_back(k);
  sort(ans.begin(),ans.end());
  cout << maxcnt << endl;
  for(auto t: ans) cout << t << " ";
  return 0;
}