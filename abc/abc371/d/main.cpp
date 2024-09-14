#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n, q; cin >> n;
  vector<int> x(n), p(n);
  REP(i,n) cin >> x[i];
  REP(i,n) cin >> p[i];
  cin >> q;

  vector<ll> s(n+1);
  REP(i,n) s[i+1] = s[i]+p[i];

  REP(_,q) {
    int l,r; cin >> l >> r;
    int left = lower_bound(x.begin(), x.end(), l) - x.begin();
    int right = upper_bound(x.begin(), x.end(), r) - x.begin() - 1;
    cout << (left <= right ? s[right+1] - s[left] : 0LL) << endl;
  }
  return 0;
}