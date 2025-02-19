#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,k; cin >> n >> k;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  const int m = 1e6;

  vector<int> num(m+1),c(m+1),best(m+1);
  for(int na: a) num[na]++;
  for(int j = 1; j <= m; j++) {
    for(int i = j; i <= m; i+=j) c[j]+=num[i];
  }

  for(int g = 1; g <= m; g++) if (c[g] >= k) {
    for(int i = g; i <= m; i+=g) best[i] = g;
  }

  REP(i,n) cout << best[a[i]] << endl;
  return 0;
}
