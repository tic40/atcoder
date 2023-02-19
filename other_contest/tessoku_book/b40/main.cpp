#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<int> a(101);
  REP(i,n) {
    int x; cin >> x;
    a[x%100]++;
  }

  ll ans = 0;
  for(int i = 1; i <= 49; i++) ans += a[i] * a[100-i];
  ans += (ll)a[0]*(a[0]-1) / 2;
  ans += (ll)a[50]*(a[50]-1) / 2;

  cout << ans << endl;
  return 0;
}