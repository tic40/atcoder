#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int n;
vector<int> a,b;

int solve() {
  ll sum = 0;
  vector<ll> d(n);
  REP(i,n) {
    d[i] = b[i] - a[i];
    sum += d[i];
  }
  if (0 < sum) return -1;

  sort(d.begin(), d.end());
  int ans = 0, pointer = 0;
  ll m = 0;
  REP(i,n) {
    while(0 < d[i]) {
      if (d[i] <= m) {
        m -= d[i];
        d[i] = 0;
      } else {
        m += abs(d[pointer]);
        pointer++;
      }
      ans++;
    }
  }
  return ans;
}

int main() {
  cin >> n;
  a.resize(n);
  b.resize(n);
  REP(i,n) cin >> a[i];
  REP(i,n) cin >> b[i];

  cout << solve() << endl;
  return 0;
}