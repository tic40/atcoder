#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; ll t;
  cin >> n >> t;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  t %= accumulate(a.begin(),a.end(),0LL);
  REP(i,n) {
    t -= a[i];
    if (t <= 0) {
      cout << i+1 << " " << a[i]+t << endl;
      break;
    }
  }

  return 0;
}