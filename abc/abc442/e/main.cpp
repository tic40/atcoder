#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<ll, ll>;

// 外積
ll cross(P a, P b) {
  return a.first * b.second - a.second * b.first;
}

// 内積
ll dot(P a, P b) {
  return a.first * b.first + a.second * b.second;
}

// false: [0,180), true: [180,360)
bool half(P p) {
  auto [x, y] = p;
  return y < 0 || (y == 0 && x < 0);
}

// 偏角の昇順（反時計回り）
bool cmp(P a, P b) {
  if (half(a) != half(b)) return half(a) < half(b);
  return cross(a, b) > 0;
}

int main() {
  int n, q; cin >> n >> q;
  vector<P> pt;
  REP(i,n) {
    int x,y; cin >> x >> y;
    pt.emplace_back(x,y);
  }

  // モンスターの元の番号
  vector<int> ord(n);
  iota(ord.begin(),ord.end(),0);

  // 外積による偏角ソート
  sort(ord.begin(), ord.end(), [&](int i, int j) {
    return cmp(pt[i], pt[j]);
  });

  // 反時計回り → 時計回り
  reverse(ord.begin(), ord.end());

  // 元の番号 -> ソート後の位置
  vector<int> rev(n);
  REP(i,n) rev[ord[i]] = i;

  // 同じ方向かどうか
  auto same = [&](int i, int j) {
    return cross(pt[i], pt[j]) == 0 && dot(pt[i], pt[j]) > 0;
  };

  // 同じ角度のグループの左右端
  vector<int> l(n),r(n);
  for(int i = 1; i < n; i++) {
    if (same(ord[i], ord[i-1])) l[i] = l[i-1];
    else l[i] = i;
  }

  r[n - 1] = n;
  for (int i = n - 2; i >= 0; i--) {
    if (same(ord[i], ord[i+1])) r[i] = r[i+1];
    else r[i] = i+1;
  }

  REP(_,q) {
    int a, b; cin >> a >> b; --a; --b;
    int L = l[rev[a]];
    int R = r[rev[b]];
    cout << (L < R ? R-L : n-L+R) << endl;
  }

  return 0;
}

