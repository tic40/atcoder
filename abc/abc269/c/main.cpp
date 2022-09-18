#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

ll n;
vector<ll> ans;
void dfs(int i, ll x) {
  if (i == 60) { ans.push_back(x); return; }

  dfs(i+1,x);
  if (n >> i & 1) dfs(i+1, x + powl(2,i));
}

int main() {
  cin >> n;
  dfs(0,0);

  sort(ans.begin(),ans.end());
  for(auto v: ans) cout << v << endl;
  return 0;
}