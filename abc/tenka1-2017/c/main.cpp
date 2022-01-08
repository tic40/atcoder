#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int main() {
  ll N; cin >> N;
  // 4/N = 1/h + 1/n + 1/w
  // 4hnw = Nnw + Nhw + Nnh
  // 4hnw - Nhw - Nnh = Nnw
  // h(4nw-Nw-Nn)=Nnw
  // h = Nnw / (4nw-Nw-Nn)

  REP(n,3501) REP(w,3501) {
    if (n==0 || w == 0) continue;

    ll a = N*n*w;
    ll b = 4*n*w - N*w - N*n;
    bool ok = 0<b && a%b==0; // 正整数となるhが存在するか

    if (ok) {
      ll h = a/b;
      cout << h << " " << n << " " << w << endl;
      return 0;
    }
  }

  return 0;
}