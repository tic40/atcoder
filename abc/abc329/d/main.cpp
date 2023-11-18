#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n,m; cin >> n >> m;
  vector<int> a(m);
  REP(i,m) { cin >> a[i]; a[i]--; }

  P mx = {0,0};
  vector<int> now(n);
  REP(i,m) {
    now[a[i]]++;
    if (now[a[i]] >= mx.first) {
      bool ng = now[a[i]] == mx.first && a[i] > mx.second;
      if (!ng) mx = { now[a[i]], a[i] };
    }
    cout << mx.second + 1 << endl;
  }
  return 0;
}