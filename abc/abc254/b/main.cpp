#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n; cin >> n;
  vector<int> a;
  REP(i,n) {
    vector<int> b(i+1,1);
    for(int j = 1; j < i; j++) {
      b[j] = a[j]+a[j-1];
    }
    for(int v: b) cout << v << " ";
    cout << endl;
    swap(a,b);
  }
  return 0;
}