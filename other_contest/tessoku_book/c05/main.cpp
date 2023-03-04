#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  n--;
  vector<int> d(10);
  REP(i,10) {
    d[i] = n & 1;
    n = n >> 1;
  }
  reverse(d.begin(),d.end());
  REP(i,10) cout << (d[i] == 1 ? 7 : 4);
  return 0;
}