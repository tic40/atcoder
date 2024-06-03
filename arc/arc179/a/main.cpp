#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,k; cin >> n >> k;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  if (k > 0) {
    sort(a.begin(),a.end());
  } else {
    ll sum = accumulate(a.begin(),a.end(),0LL);
    if (sum < k) { cout << "No" << endl; return 0; }
    sort(a.rbegin(),a.rend());
  }

  cout << "Yes" << endl;
  for(auto v: a) cout << v << " ";
  return 0;
}