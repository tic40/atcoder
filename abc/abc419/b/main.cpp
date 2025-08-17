#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int q; cin>> q;
  priority_queue<int, vector<int>, greater<int>> pq;
  REP(_,q) {
    int t; cin >> t;
    if (t == 1) { int x; cin >> x; pq.push(x); }
    if (t == 2) { cout << pq.top() << endl; pq.pop(); }
  }
  return 0;
}