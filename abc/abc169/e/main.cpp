#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a(n),b(n);
  REP(i,n) cin >> a[i] >> b[i];

  sort(a.begin(),a.end());
  sort(b.begin(),b.end());

  int ans = 0;
  if (n%2 == 0) {
    ans = (b[n/2-1] + b[n/2]) - (a[n/2-1] + a[n/2]) + 1;
  } else {
    ans = b[n/2] - a[n/2] + 1;
  }

  cout << ans << endl;
  return 0;
}