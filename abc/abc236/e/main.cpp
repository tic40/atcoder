#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

template<typename T>
void chmax(T& a, const T& b) { a = max(a,b); }

double maxSum(vector<double> a) {
  int n = a.size();
  // 0: 直前を取ってない, 1: 取った
  vector<double> dp(2, -1e18);
  dp[1] = 0; // 範囲外だが直前は取っているものとする
  REP(i,n) {
    vector<double> p(2, -1e18);
    swap(dp, p);
    // j: 直前
    REP(j,2) {
      // 直前に関わらず取ることはできる
      chmax(dp[1], p[j]+a[i]);
      // 直前を選んだときは0(選ばない)選択肢がある
      if (j) chmax(dp[0], p[j]);
    }
  }
  return max(dp[0],dp[1]);
}

double solveAve(vector<int> a) {
  int n = a.size();
  double ac = 0, wa = 1e9;
  REP(ti, 50) {
    double wj = (ac+wa)/2;
    vector<double> na(n);
    REP(i,n) na[i] = a[i]-wj;
    if (maxSum(na) >= 0) ac = wj;
    else wa = wj;
  }
  return ac;
}

bool canMedOne(vector<int> a) {
  int n = a.size();
  int one = 0;
  REP(i,n) if (a[i] == 1) one++;
  // 0の個数の最小値
  int zero = 0;
  // 連続する0の個数
  int now = 0;
  REP(i,n) {
    // a[i] == 1 は全部撮っていい
    // a[i] == 0 を取る数を最小化したい
    if (a[i] == 1) {
      zero += now/2;
      now = 0;
    } else {
      ++now;
    }
  }
  zero += now/2;
  return zero <= one-1;
}

int solveMed(vector<int> a) {
  int n = a.size();
  int ac = 1, wa = 1001001001;
  while(wa-ac > 1) {
    int wj = (ac+wa)/2;
    vector<int> na(n);
    REP(i,n) na[i] = a[i] >= wj;
    if (canMedOne(na)) ac = wj;
    else wa = wj;
  }
  return ac;
}

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  printf("%.4f\n", solveAve(a));
  cout << solveMed(a) << endl;
}