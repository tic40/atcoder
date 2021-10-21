#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int n,m;
vector<int> heap_sort(vector<int> a, int n, int x) {
  while(0 <= x) {
    int k = x;
    while(2*k+1 < n) { // 子ノードが存在する
      int mx_idx = k;
      if (a[max_idx] < a[2*k+1]) max_idx = 2*k+1;
      if (2*k+2 < n) {
        if (a[max_idx] < a[2*k+2]) max_idx = 2*k+2;
      }
      if (k == max_idx) break;
      swap(a[k],a[max_idx]);
      k = max_idx;
    }
    x--;
  }
  return a;
}

vector<int> solve(vector<int> a) {
  a = heap_sort(a, a.size(), a.size()/2-1);

  for(int i = n-1; 0 < i; i--) {
    swap(a[0],a[i]);
    a = heap_sort(a,i,0);
    if (i == m) {
      for(int v: a) cout << v << " ";
      cout << endl;
    }
  }

  return a;
}

int main() {
  cin >> n >> m;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  auto res = solve(a);
  for(int v: res) cout << v << " ";
  cout << endl;

  return 0;
}