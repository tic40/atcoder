#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const ll LINF = numeric_limits<ll>::max();

struct Point {
  ll px, py;
  // Point(ll px=0, ll py=0): px(px),py(py) {};
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

int main() {
  ll N; cin >> N;
  vector<Point> V,G(N);
  REP(i,N) cin >> G[i].px >> G[i].py;
  sort(G.begin(),G.end());
	V.push_back(G[0]);
	V.push_back(G[1]);
	V.push_back(G[2]);

  vector<ll> ly(100009,LINF),ry(100009,-LINF);

	// Step #2. 各 x に対する下端と上端を求める
	for (int i = 0; i < (int)V.size(); i++) {
		ll ax = V[(i + 0) % V.size()].px, ay = V[(i + 0) % V.size()].py;
		ll bx = V[(i + 1) % V.size()].px, by = V[(i + 1) % V.size()].py;
		if (ax > bx) { swap(ax, bx); swap(ay, by); }
		if (ax == bx) {
			ly[ax] = min({ ly[ax], ay, by });
			ry[ax] = max({ ry[ax], ay, by });
		}
		else {
			for (int i = ax; i <= bx; i++) {
				ll v1 = (ay * (bx - i) + by * (i - ax)) / (bx - ax);
				ll v2 = (ay * (bx - i) + by * (i - ax) + (bx - ax) - 1LL) / (bx - ax);
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
	cout << ans - N << endl;
	return 0;
}