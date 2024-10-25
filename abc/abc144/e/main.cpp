#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; ll k; cin >> n >> k;
  vector<int> a(n),f(n);
  REP(i,n) cin >> a[i];
  REP(i,n) cin >> f[i];
  sort(a.begin(),a.end());
  sort(f.rbegin(),f.rend());

  //すべての cost を x 以下にできるか？
  auto check = [&](ll x) {
    ll tot = 0;
    REP(i,n) if ((ll)a[i]*f[i] > x) {
      tot += a[i] - (x/f[i]);
      if (tot > k) return false;
    }
    return true;
  };

  ll ok = 1e15, ng = -1;
  while(ok-ng>1) {
    ll mid = (ok+ng)/2;
    if (check(mid)) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
  return 0;
}