#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int q;
int main() {
  cin >> q;
  queue<int> que1;
  priority_queue<int, vector<int>, greater<int>> que2;

  REP(i,q) {
    int c; cin >> c;
    if (c == 1) {
      int x; cin >> x;
      que1.push(x);
    } else if (c == 2) {
      if (que2.size()) {
        cout << que2.top() << endl;
        que2.pop();
      } else {
        cout << que1.front() << endl;
        que1.pop();
      }
    } else {
      while(que1.size()) {
        que2.push(que1.front());
        que1.pop();
      }
    }
  }

  return 0;
}