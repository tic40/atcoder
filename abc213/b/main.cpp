#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  int n;
  cin >> n;
  vector<pair<int,int>> a(n);
  REP(i,n) {
    int _; cin >> _;
    a[i] = { _, i };
  }

  sort(a.rbegin(), a.rend());
  cout << (a[1].second + 1) << endl;
  return 0;
}