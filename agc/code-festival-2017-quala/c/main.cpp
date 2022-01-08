#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int h,w;
vector<string> a;

bool solve() {
  map<char, int> cnt;
  REP(i,h) REP(j,w) {
    cnt[ a[i][j] ]++;
  }

  bool ok = true;
  // どちらも偶数
  // 同じパターンが4つ、すべての文字の個数が4の倍数であるとき成立
  if (h%2 == 0 && w%2 == 0) {
    for(auto v: cnt) {
      if (v.second % 4 != 0) ok = false;
    }
  // どちらも奇数
  // 真ん中は4で割ると1余る数になる必要がある
  // 残りは4で割ると2余る数が使われるのが(h-1)/2 + (w-1)/2 以下
  } else if (h%2 == 1 && w%2 == 1) {
    map<int, int> c;
    for(auto v: cnt) c[v.second % 4]++;
    if (c[3]) ok = false;
    if (c[1] != 1) ok = false;
    if (c[2] > (h-1) / 2 + (w-1) / 2) ok = false;
  // 奇数と偶数
  // 中心の行は横の回文でしか使われないのでここは2の倍数
  // 4で割ると2余る数がw/2個以下で残りが4の倍数
  } else {
    if (w%2) swap(h,w);
    map<int, int> c;
    for(auto v: cnt) c[v.second % 4]++;
    if (c[1] || c[3]) ok = false;
    if (c[2] > w/2) ok = false;
  }

  return ok;
}

int main() {
  cin >> h >> w;
  a.resize(h);
  REP(i,h) cin >> a[i];

  cout << (solve() ? "Yes" : "No") << endl;
  return 0;
}