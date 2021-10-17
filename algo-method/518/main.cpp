#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

vector<int> heap_sort(vector<int> a) {
  int n = a.size();
  int x = n / 2 - 1;

  while(0 <= x) {
    int k = x;
    while(1) {
      int idx = k;
      if (2*k+1 < n) {
        if (a[idx] < a[2*k+1]) idx = 2*k+1;
      }
      if (2*k+2 < n) {
        if (a[idx] < a[2*k+2]) idx = 2*k+2;
      }
      if (k == idx) break;

      swap(a[k],a[idx]);
      k = idx;
    }
    x--;
  }

  return a;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  auto res = heap_sort(a);
  for(int v: res) cout << v << " ";
  cout << endl;

  return 0;
}