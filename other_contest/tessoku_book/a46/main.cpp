#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;
const int INF = numeric_limits<int>::max();

int n;
vector<int> x(150),y(150);

int f(int i, int j) {
  return pow(x[i]-x[j],2) + pow(y[i]-y[j],2);
}

int rand_int(int a, int b) {
  return a + rand() % (b - a + 1);
}

double rand_double() {
  return 1.0 * rand() / RAND_MAX;
}

// greedy
void solve1() {
  vector<int> ans;
  vector<bool> visited(n);

  auto push = [&](int i) {
    ans.push_back(i);
    visited[i] = true;
  };

  push(0);
  for(int i = 1; i < n; i++) {
    P mx = {INF,0};
    for(int j = 1; j < n; j++) {
      if (visited[j]) continue;
      int d = f(ans[i-1],j);
      if (d < mx.first) { mx = {d,j}; }
    }
    push(mx.second);
  }
  push(0);
  for(int v: ans) cout << v+1 << endl;
  return;
}

// 局所探索(山登り法)
void solve2() {
  vector<int> p(n+1);
  iota(p.begin(),p.end(),0);
  p[n] = 0;

  auto score = [](vector<int> &p) {
    int sum = 0;
    REP(i,n) sum += f(p[i],p[i+1]);
    return sum;
  };

  int cur_score = score(p);
  REP(_, 2e5) {
    int l = rand_int(1,n-1);
    int r = rand_int(1,n-1);
    if (l > r) swap(l,r);

    reverse(p.begin()+l, p.begin()+r+1);
    int new_score = score(p);

    if (cur_score >= new_score) cur_score = new_score;
    else reverse(p.begin()+l, p.begin()+r+1);
  }

  for(int v: p) cout << v+1 << endl;
  return;
}

// 焼きなまし法
void solve3() {
  vector<int> p(n+1);
  iota(p.begin(),p.end(),0);
  p[n] = 0;

  auto score = [](vector<int> &p) {
    int sum = 0;
    REP(i,n) sum += f(p[i],p[i+1]);
    return sum;
  };

  int cur_score = score(p);
  REP(_, 2e5) {
    int l = rand_int(1,n-1);
    int r = rand_int(1,n-1);
    if (l > r) swap(l,r);

    reverse(p.begin()+l, p.begin()+r+1);
    int new_score = score(p);

    double t = 30.00 - 28.00 * t / 200000.0;
    double probability = exp(min(0.0, (cur_score - new_score) / t));
    if (rand_double() < probability) cur_score = new_score;
    if (cur_score >= new_score) cur_score = new_score;
    else reverse(p.begin()+l, p.begin()+r+1);
  }

  for(int v: p) cout << v+1 << endl;
  return;
}

int main() {
  cin >> n;
  REP(i,n) cin >> x[i] >> y[i];

  // solve1();
  // solve2();
  solve3();
  return 0;
}