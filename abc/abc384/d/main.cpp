#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; ll s; cin >> n >> s;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  vector<ll> sum(n*2+1);
  REP(i,n*2) sum[i+1] = sum[i] + a[i%n];

  s %= accumulate(a.begin(),a.end(),0LL);
  int ok = 0;
  REP(i,n) ok |= binary_search(sum.begin(),sum.end(),sum[i]+s);
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}