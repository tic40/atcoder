#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int n;
vector<int> a;

vector<int> bucket_sort(vector<int> a) {
  int x = 100000;
  int n = a.size();
  vector<int> num(x), acc(x);
  REP(i,n) num[ a[i] ]++;
  REP(i,x) {
    if (i == 0) acc[i] = num[i];
    else acc[i] = acc[i-1] + num[i];
  }
  vector<int> b(n);
  REP(i,n) {
    acc[a[i]]--;
    b[acc[a[i]]] = a[i];
  }

  return b;
}

int main() {
  cin >> n;
  a.resize(n);
  REP(i,n) cin >> a[i];

  auto res = bucket_sort(a);
  for(int v: res) cout << v << " ";
  cout << endl;
  return 0;
}