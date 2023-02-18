#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,h,w; cin >> n >> h >> w;
  vector<int> d;
  REP(i,n) {
    int a,b; cin >> a >> b;
    a--; b--;
    d.push_back(a);
    d.push_back(b);
  }

  int xsum = 0;
  for(int v: d) xsum ^= v;
  cout << (xsum > 0 ? "First" : "Second") << endl;
  return 0;
}