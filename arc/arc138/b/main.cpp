#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n; cin >> n;
  deque<int> d;
  REP(i,n) {
    int a; cin >> a;
    d.push_back(a);
  }

  int flip = 0;
  REP(i,n) {
    int bk = d.back() ^ flip;
    int fr = d.front() ^ flip;

    if (bk == 0) {
      d.pop_back();
    } else if (fr == 0) {
      d.pop_front();
      flip ^= 1;
    } else {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  return 0;
}