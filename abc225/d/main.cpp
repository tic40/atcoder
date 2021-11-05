#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> top(n,-1),back(n,-1);
  REP(i,q) {
    int t,x,y;
    cin >> t;

    if (t == 1) {
      cin >> x >> y;
      x--; y--;
      back[x] = y;
      top[y] = x;
    } else if (t == 2) {
      cin >> x >> y;
      x--; y--;
      back[x] = -1;
      top[y] = -1;
    } else {
      cin >> x; x--;
      vector<int> res;
      while(top[x] != -1) x = top[x];
      while(x != -1) {
        res.push_back(x);
        x = back[x];
      }
      cout << res.size() << " ";
      for(int v: res) cout << v+1 << " ";
      cout << endl;
    }
  }
  return 0;
}