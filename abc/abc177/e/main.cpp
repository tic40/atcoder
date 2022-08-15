#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a(n),c(1e6+5);
  REP(i,n) {
    cin >> a[i];
    c[a[i]]++;
  }

  bool pairwise = true;
  // 同じ倍数で割れる数が2つ以上あればpairwiseではない
  for(int i = 2; i <= 1e6; i++) {
    int cnt = 0;
    for(int j = i; j <= 1e6; j+=i) cnt += c[j];
    if (cnt > 1) pairwise = false;
  }
  if (pairwise) {
    cout << "pairwise coprime" << endl;
    return 0;
  }

  int g = 0;
  REP(i,n) g = gcd(g,a[i]);
  if (g == 1) {
    cout << "setwise coprime" << endl;
    return 0;
  }

  cout << "not coprime" << endl;
  return 0;
}