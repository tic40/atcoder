#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,k; cin >> n >> k;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];

  priority_queue<ll, vector<ll>, greater<ll>> q;
  REP(i,n) q.push(a[i]);

  int cnt = 0;
  ll now = -1, prev = -1;
  while(cnt < k) {
    swap(now,prev);
    now = q.top(); q.pop();
    if (now == prev) continue;

    REP(i,n) q.push(now + a[i]);
    cnt++;
  }

  cout << now << endl;
  return 0;
}