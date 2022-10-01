#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a(n);
  set<int> st;
  REP(i,n) {
    cin >> a[i];
    st.insert(a[i]);
  }

  int ok = 0, ng = n+1;
  while(abs(ok-ng) > 1) {
    int mid = (ok+ng)/2; // mid巻まで読めるかどうか
    int sell = n - st.size();
    sell += distance(st.upper_bound(mid), st.end());

    for(int i = 1; i <= mid; i++) {
      if (st.count(i) == 0) sell -= 2;
    }
    if (sell >= 0) ok = mid;
    else ng = mid;
  }

  cout << ok << endl;
  return 0;
}