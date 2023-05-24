#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,k; cin >> n >> k;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  int t = 1, b = n*(n+1)/2;
  REP(i,n) {
    vector<int> small, large;
    for(int j = i+1; j < n; j++) {
      a[j] < a[i] ? small.push_back(a[j]) : large.push_back(a[j]);
    }
    int x = -1;
    if (k - t < int(small.size())) {
      sort(small.begin(),small.end());
      x = small[k-t];
    }
    if (b - k < int(large.size())) {
      sort(large.begin(),large.end());
      reverse(large.begin(),large.end());
      x = large[b-k];
    }
    if (x != -1) {
      int j = i;
      while (a[j] != x) j++;
      reverse(a.begin()+i, a.begin()+j+1);
      break;
    }
    t += small.size();
    b -= large.size();
  }
  REP(i,n) cout << a[i] << " ";
  return 0;
}