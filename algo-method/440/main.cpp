#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
const int INF = 1e9;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  REP(i,n-1) {
    pair<int,int> mn = { 0, INF }; // idx, value
    for(int j = i; j < n; j++) {
      if (a[j] < mn.second) mn = {j, a[j]};
    }
    swap(a[i],a[mn.first]);
    REP(i,n) cout << a[i] << " ";
    cout << endl;
  }
  return 0;
}