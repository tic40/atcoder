#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int q; cin >> q;
  priority_queue<int, vector<int>, greater<int>> que;
  REP(_,q) {
    int t; cin >> t;
    if (t == 1) {
      int x; cin >> x;
      que.push(x);
    } else if (t == 2) {
      cout << que.top() << endl;
    } else {
      que.pop();
    }
  }
  return 0;
}