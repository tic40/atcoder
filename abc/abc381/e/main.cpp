#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const int INF = numeric_limits<int>::max();

int main() {
  int n,q; cin >> n >> q;
  string s; cin >> s;

  vector is(3,vector<int>());
  REP(i,n) {
    int now = s[i] == '/' ? 0 : s[i]-'0';
    is[now].push_back(i);
  }

  // c: 文字種, i: 位置, x: 連続する文字数
  auto getNext = [&](int c, int i, int x) {
    if (x == 0) return i;
    auto& nis = is[c];
    int j = lower_bound(nis.begin(),nis.end(),i) - nis.begin();
    j += x-1;
    return j < (int)nis.size() ? nis[j]+1 : INF;
  };

  REP(qi,q) {
    int l,r; cin >> l >> r;
    l--; // 半開区間

    auto judge = [&](int k) {
      int i = l;
      i = getNext(1,i,k);
      i = getNext(0,i,1); // slash
      i = getNext(2,i,k);
      return i <= r;
    };

    int ok = -1, ng = n;
    while(ng-ok>1) {
      int mid = (ok+ng)/2;
      if (judge(mid)) ok = mid;
      else ng = mid;
    }
    cout << (ok == -1 ? 0 : ok*2+1) << endl;
  }
  return 0;
}