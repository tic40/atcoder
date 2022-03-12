#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int main() {
  int v; cin >> v;
  vector<int> a(3);
  REP(i,3) cin >> a[i];
  vector<char> vc = { 'F', 'M', 'T'};

  int cnt = 0;
  while(true) {
    v -= a[cnt%3];
    if (v < 0) {
      cout << vc[cnt % 3] << endl;
      return 0;
    }
    cnt++;
  }

  return 0;
}