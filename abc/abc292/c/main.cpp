#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;

  vector<int> f(n+1);
  for(int a = 1; a <= n; a++) {
    for(int b = 1; a*b <= n; b++) {
      f[a*b]++;
    }
  }

  ll ans = 0;
  for(int i = 1; i < n; i++) ans += f[i]*f[n-i];
  cout << ans << endl;
  return 0;
}