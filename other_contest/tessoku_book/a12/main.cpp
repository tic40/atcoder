#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,k; cin >> n >> k;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  int ok = 1e9, ng = 0;
  while(ok - ng > 1) {
    int mid = (ok+ng) / 2;
    ll now = 0;
    REP(i,n) now += mid / a[i];
    if (k <= now) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
  return 0;
}