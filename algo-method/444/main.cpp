#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

vector<int> merge_sort(vector<int> a) {
  int n = a.size();
  int mid = n/2;
  vector<int> l,r;

  REP(i,n) i < mid ? l.push_back(a[i]) : r.push_back(a[i]);

  if (1 < l.size()) l = merge_sort(l);
  if (1 < r.size()) r = merge_sort(r);
  for(int i = r.size()-1; 0 <= i; i--) l.push_back(r[i]);

  vector<int> res;
  int pl = 0, pr = l.size()-1;
  while(pl <= pr) {
    if (l[pl] <= l[pr]) {
      res.push_back(l[pl]);
      pl++;
    } else {
      res.push_back(l[pr]);
      pr--;
    }
  }

  return res;
}

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  auto res = merge_sort(a);
  for(int v: res) cout << v << " ";
  cout << endl;

  return 0;
}