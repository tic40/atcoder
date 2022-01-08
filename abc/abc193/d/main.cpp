#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

ll k;
vector<int> s(5),t(5);

ll score(vector<int> a) {
  vector<int> cnt(10);
  for(int x: a) cnt[x]++;

  ll res = 0;
  for(int i = 1; i < 10; i++) res += i*pow(10, cnt[i]);
  return res;
}

double solve() {
  vector<int> cnt(10);
  // それぞれカードの回数をカウント
  REP(i,4) cnt[s[i]]++;
  REP(i,4) cnt[t[i]]++;

  ll win = 0;
  for(int i = 1; i < 10; i++) {
    for(int j = 1; j < 10; j++) {
      s.back() = i;
      t.back() = j;
      // カードはそれぞれk枚しか存在しないためk枚を越える場合はスキップ
      if (k < cnt[i]+1 || k < cnt[j]+1) continue;
      if (i==j && k < cnt[i]+2) continue;

      // 高橋くんが青木くんより点数が高い場合
      if (score(t) < score(s)) {
        // i, j の組み合わせは、(k - カードiの残っている数) * (k - カードjの残っている数)
        // i==j のケースは考慮が必要
        win += (k-cnt[i]) * (k-cnt[j] - (i==j));
      }
    }
  }

  // 全事象: 9*k枚のカードから表になっているカード8枚(4*2)を引いた分を配ったときの総数
  ll tot = (9*k-8)*(9*k-9);
  return double(win) / tot;
}

int main() {
  string _s, _t;
  cin >> k >> _s >> _t;
  REP(i,4) s[i] = _s[i]-'0';
  REP(i,4) t[i] = _t[i]-'0';

  cout << solve() << endl;
  return 0;
}