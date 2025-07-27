#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,k,x; cin >> n >> k >> x;
  vector<string> s(n);
  REP(i,n) cin >> s[i];

  vector<string> t;
  auto dfs = [&](auto dfs, int i, string now) {
    if (i == k) { t.push_back(now); return; }
    REP(j,n) dfs(dfs,i+1,now+s[j]);
  };
  dfs(dfs,0,"");
  sort(t.begin(),t.end());
  cout << t[x-1] << endl;
  return 0;
}