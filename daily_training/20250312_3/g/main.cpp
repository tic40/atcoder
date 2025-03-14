#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,k; cin >> n >> k;
  vector<int> p(n);
  REP(i,n) cin >> p[i];

  priority_queue<int, vector<int>, greater<int>> pq;
  REP(i,k) pq.push(p[i]);

  cout << pq.top() << endl;
  for(int i = k; i < n; i++) {
    if (pq.top() < p[i]) { pq.pop(); pq.push(p[i]); }
    cout << pq.top() << endl;
  }
  return 0;
}
