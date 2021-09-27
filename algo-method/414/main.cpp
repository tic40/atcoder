#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) x.begin(), x.end()

void output(vector<int> d) {
  sort(ALL(d));
  REP(i, d.size()) {
    if (0 < i) cout << " ";
    cout << d[i];
  }
  cout << endl;
  return;
};

int main() {
  int n,m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  REP(i,m) {
    int a,b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector<int> color(n);
  vector<int> prev;
  REP(i,n) {
    vector<int> cur;
    if (i == 0) {
      cur.push_back(0);
      color[0] = 1;
    } else {
      for(int j: prev) for(int k: g[j]) {
        if (!color[k]) {
          color[k] = 1;
          cur.push_back(k);
        }
      }
    }

    output(cur);
    swap(cur,prev);
  }
  return 0;
}