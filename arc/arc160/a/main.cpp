#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,k; cin >> n >> k;
  k--;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  int snum = 0, lnum = 0;
  int tot = n*(n+1)/2 - 1;
  REP(i,n) {
    vector<int> small,large;
    for(int j = i+1; j < n; j++) {
      a[j] < a[i] ? small.push_back(a[j]) : large.push_back(a[j]);
    }
    int x = -1;
    if (k-snum < int(small.size())) {
      sort(small.begin(),small.end());
      x = small[k-snum];
    }
    if (tot-k-lnum < int(large.size())) {
      sort(large.rbegin(),large.rend());
      x = large[tot-lnum-k];
    }
    if (x != -1) {
      int l = i, r = i;
      while (a[r] != x) r++;
      reverse(a.begin()+l, a.begin()+r+1);
      break;
    }
    snum += small.size();
    lnum += large.size();
  }
  REP(i,n) cout << a[i] << " ";
  return 0;
}