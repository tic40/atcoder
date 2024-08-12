#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,k; cin >> n >> k;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  int j = 0;
  ll now = 0;
  int ans = 0;
  REP(i,n) {
    while(j < n && now+a[j] <= k) { now += a[j]; j++; }
    ans += j-i;
    if (j == i) j++;
    else now -= a[i];
  }
  cout << ans << endl;
  return 0;
}