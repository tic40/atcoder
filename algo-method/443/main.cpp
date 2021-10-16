#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

// 乱択クイックソート
vector<int> quick_sort(vector<int> a) {
  int n = a.size();
  vector<int> l,r;
  int x = rand() % n;

  REP(i,n) {
    if (i==x) continue;

    if (a[i] < a[x]) l.push_back(a[i]);
    else if (a[x] < a[i]) r.push_back(a[i]);
    else rand()%2 ? l.push_back(a[i]) : r.push_back(a[i]);
  }
  if (l.size()) l = quick_sort(l);
  if (r.size()) r = quick_sort(r);

  vector<int> res;
  for(int v: l) res.push_back(v);
  res.push_back(a[x]);
  for(int v: r) res.push_back(v);
  return res;
}

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  auto b = quick_sort(a);
  for(int v: b) cout << v << " ";
  cout << endl;
  return 0;
}