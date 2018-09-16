struct loc {
	int x, y;
	loc() {};
	loc(int x, int y): x(x), y(y) {}
	bool operator <(const loc& b)const {return x != b.x ? x < b.x : y < b.y;}
	bool operator ==(const loc& b)const {return x == b.x && y == b.y;}
	loc operator -(const loc& b)const {return loc(x - b.x, y - b.y);}
	int cross(const loc& b)const {return x * b.y - y * b.x;}
	int dis(loc a, loc b) {return (x - b.x) * (x - b.x) + (y - b.y) * (y - b.y);}
};
vector<loc>p, p1;
int n;
void convexhull() {
	sort(p.begin(), p.end());
	p.erase(unique(p.begin(), p.end()), p.end());
	p1.clear();
	p1.resize(p.size());
	int m = 0;
	for (int i = 0; i < p.size(); i++) {
		while (m > 1 && (p1[m - 1] - p1[m - 2]).cross(p[i] - p1[m - 2]) <= 0)m--;
		p1[m++] = p[i];
	}
	int k = m;
	for (int i = p.size() - 2; i >= 0; i--) {
		while (m > k && (p1[m - 1] - p1[m - 2]).cross(p[i] - p1[m - 2]) <= 0)m--;
		p1[m++] = p[i];
	}
	if (n > 1)m--;
	p1.resize(m);
}