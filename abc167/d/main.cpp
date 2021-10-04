#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) x.begin(), x.end()
using ll = long long;

ll n,k;
vector<int> a(200005);
int doubling[100][200005]; // 町iから2^k先の町はどこか?

void solve() {
  int logK = 1;
  while ((1LL << logK) <= k) logK++;

  // doubling[k][i] : i番目から 2^k 進んだ町
  REP(i,n) doubling[0][i] = a[i];

  // 前処理 doubling の計算
  REP(i,logK-1) REP(j,n) {
    doubling[i+1][j] = doubling[i][doubling[i][j]];
  }

  int now = 0;
  REP(i,logK) {
    if ((k >> i) & 1) now = doubling[i][now];
  }

  cout << now+1 << endl;
  return;
}

int main() {
  cin >> n >> k;
  REP(i,n) {
    cin >> a[i];
    a[i]--;
  }

  solve();
  return 0;
}