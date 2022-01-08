#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<int> t(n),a(n);
  REP(i,n) cin >> t[i] >> a[i];

  ll T = 1, A = 1;
  REP(i,n) {
    ll div = max((T+t[i]-1)/t[i], (A+a[i]-1)/a[i]);
    T = t[i]*div; A = a[i]*div;
  }
  cout << T + A << endl;
}