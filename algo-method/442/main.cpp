#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

vector<int> quick_sort(vector<int> a) {
  int mid = a.size() / 2;
  vector<int> l,r;

  REP(i,a.size()) {
    if (i == mid) continue;

    if (a[i] < a[mid]) l.push_back(a[i]);
    else r.push_back(a[i]);
  }

  vector<int> res;
  if (l.size()) for (int v: quick_sort(l)) res.push_back(v);
  res.push_back(a[mid]);
  if (r.size()) for (int v: quick_sort(r)) res.push_back(v);
  return res;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  auto ans = quick_sort(a);
  for (int v: ans) cout << v << " ";
  cout << endl;

  return 0;
}