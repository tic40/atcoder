#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  int prev = 0;
  int now = 0;
  REP(i,n) {
    int t,v; cin >> t >> v;
    now = max(0, now - (t - prev));
    now += v; prev = t;
  }
  cout << now << endl;

  return 0;
}