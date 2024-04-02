#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,a,b; cin >> n >> a >> b;
  vector<int> d(n);
  REP(i,n) cin >> d[i];
  int w = a+b;
  REP(i,n) d[i] %= w;
  sort(d.begin(),d.end());
  // 2 周分にする
  REP(i,n) d.push_back(d[i]+w);

  REP(i,(int)d.size()-1) {
    if (d[i+1]-d[i] >= b+1) { cout << "Yes" << endl; return 0; }
  }
  cout << "No" << endl;
  return 0;
}