#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> d(n-1);
  REP(i,n-1) cin >> d[i];

  REP(i,n) {
    int now = 0;
    for(int j = i+1; j < n; j++) cout << (now += d[j-1]) << " ";
    cout << endl;
  }
  return 0;
}