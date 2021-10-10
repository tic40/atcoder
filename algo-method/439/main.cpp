#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

void bubble_sort(vector<int>& a) {
  bool ok = true;
  while(ok) {
    ok = false;
    REP(i,a.size()-1) {
      if (a[i+1] < a[i]) {
        swap(a[i],a[i+1]);
        ok = true;
      }
    }

    if (ok) {
      for(int v: a) cout << v << " ";
      cout << endl;
    }
  }
}

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  bubble_sort(a);
  return 0;
}