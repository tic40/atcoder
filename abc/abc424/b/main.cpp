#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m,k; cin >> n >> m >> k;
  vector<int> cnt(n),ans;
  REP(i,k) {
    int a,b; cin >> a >> b; a--; b--;
    cnt[a]++;
    if (cnt[a] == m) ans.push_back(a);
  }
  for(auto v: ans) cout << v+1 << " ";
  return 0;
}