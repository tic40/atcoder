#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,h0; cin >> n;
  cin >> h0;
  REP(i,n-1) {
    int h; cin >> h;
    if (h0 < h) { cout << i+2 << endl; return 0; }
  }
  cout << -1 << endl;
  return 0;
}