#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n,w; cin >> n >> w;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  set<int> st;

  REP(i,n) {
    if (a[i] <= w) st.insert(a[i]);
    for(int j = i+1; j < n; j++) {
      if (a[i]+a[j] <= w) st.insert(a[i]+a[j]);
      for(int k = j+1; k < n; k++) {
        if (a[i]+a[j]+a[k] <= w) st.insert(a[i]+a[j]+a[k]);
      }
    }
  }

  cout << st.size() << endl;
  return 0;
}