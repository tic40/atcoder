#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int n,l,k;
vector<int> a;

bool possible(int m) {
  int cnt = 0, last = 0;
  REP(i,n) {
    int cur = a[i]-last;
    // m以上で、切った残りの部分もm以上になるときはok
    int ok = m <= cur && m <= l - a[i];

    if (ok) { cnt++; last = a[i]; }
  }
  return k <= cnt;
}

int binary_search(vector<int> a) {
  int ok = 1; // 解が存在する値
  int ng = a.back(); // 解が存在しない値

  while (abs(ok-ng) > 1) {
    int mid = ok + abs(ok - ng) / 2;

    if (possible(mid)) ok = mid;
    else ng = mid;
  }
  return ok;
}

int main() {
  cin >> n >> l >> k;
  a.resize(n);
  REP(i,n) cin >> a[i];

  cout << binary_search(a) << endl;
  return 0;
}