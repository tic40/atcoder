#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int n;
vector<int> a;

void solve() {
  map<int,int> m;
  REP(i,n) m[a[i]]++;

  int cnt = 0;
  for (auto v: m) cnt += v.second-1;

  int ans = (cnt%2) ? n-(cnt+1) : n-cnt;
  cout << ans << endl;
  return;
}

int main() {
  cin >> n;
  a.resize(n);
  REP(i,n) cin >> a[i];

  solve();
  return 0;
}