#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; ll s; cin >> n >> s;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  int n2 = n*2;
  vector<ll> sum(n2+1);
  REP(i,n2) sum[i+1] = sum[i] + a[i%n];

  s = s % accumulate(a.begin(),a.end(),0LL);
  int ok = 0;
  REP(i,n) {
    ll k = sum[i]+ s;
    ok |= k == *lower_bound(sum.begin(),sum.end(),k);
  }
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}