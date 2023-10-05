#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const ll LINF = numeric_limits<ll>::max();

struct Point {
  ll px, py;
  Point(ll px=0, ll py=0): px(px),py(py) {};
};
Point operator+(const Point& a1, const Point& a2) {
	return Point{ a1.px + a2.px, a1.py + a2.py };
}
Point operator-(const Point& a1, const Point& a2) {
	return Point{ a1.px - a2.px, a1.py - a2.py };
}
bool operator<(const Point& a1, const Point& a2) {
	if (a1.px < a2.px) return true;
	if (a1.px > a2.px) return false;
	if (a1.py < a2.py) return true;
	return false;
}

// 点 p1 と p2 の外積を求める
ll crs(Point p1, Point p2) {
	return p1.px * p2.py - p1.py * p2.px;
}

// 点 p1, p2, p3 が時計回りか反時計回りか
int ccw(Point p1, Point p2, Point p3) {
	Point va = p2 - p1;
	Point vb = p3 - p1;
	if (crs(va, vb) > 0) return 1;
	if (crs(va, vb) < 0) return -1;
	return 0;
}

int main() {
  ll n; cin >> n;
  vector<Point> v,g(n);
  REP(i,n) cin >> g[i].px >> g[i].py;

  sort(g.begin(),g.end());

  vector<Point> g1,g2;
  REP(i,2) {
    g1.push_back(g[i]);
    g2.push_back(g[i]);
  }
	for (int i = 2; i < n; i++) {
    while((int)g1.size() >= 2 && ccw(g1[g1.size()-2],g1[g1.size()-1],g[i]) == -1) {
      g1.pop_back();
    }
    while((int)g2.size() >= 2 && ccw(g2[g2.size()-2],g2[g2.size()-1],g[i]) == 1) {
      g2.pop_back();
    }
		g1.push_back(g[i]);
		g2.push_back(g[i]);
	}

  vector<Point> totsuhou;
  REP(i,(int)g1.size()) totsuhou.push_back(g1[i]);
	for (int i = (int)g2.size() - 2; i >= 1; i--) totsuhou.push_back(g2[i]);

  vector<ll> ly(100009,LINF),ry(100009,-LINF);
	// Step #2. 各 x に対する下端と上端を求める
	for (int i = 0; i < (int)totsuhou.size(); i++) {
    auto [ax,ay] = totsuhou[i];
    auto [bx,by] = totsuhou[(i+1)%totsuhou.size()];
		if (ax > bx) { swap(ax,bx); swap(ay,by); }
		if (ax == bx) {
			ly[ax] = min({ ly[ax], ay, by });
			ry[ax] = max({ ry[ax], ay, by });
		} else {
			for (int i = ax; i <= bx; i++) {
				ll v1 = (ay * (bx - i) + by * (i - ax)) / (bx - ax);
				ll v2 = (ay * (bx - i) + by * (i - ax) + bx - ax - 1LL) / (bx - ax);
				ly[i] = min(ly[i], v2);
			  ry[i] = max(ry[i], v1);
			}
		}
	}

	// Step #3. 答えを求める
	ll ans = 0;
	for (int i = 0; i <= 1000; i++) {
		if (ly[i] <= ry[i]) ans += (ry[i] - ly[i] + 1);
	}
	cout << ans - n << endl;
	return 0;
}