using f64 = double;
using dvt = f64;
struct dot{dvt x, y;};

struct line{
dot start, end;
};


dot operator+(dot a, dot b) {return {a.x+b.x, a.y+b.y};}
dot operator-(dot a, dot b) {return {a.x-b.x, a.y-b.y};}
dot operator*(dot a, dvt c) {return {a.x*c, a.y*c};}
dot operator*(dvt c, dot a) {return a*c;}
dot operator/(dot a, dvt c) {return {a.x/c, a.y/c};}
bool operator<(dot a, dot b) {
	return std::tie(a.x, a.y) < std::tie(b.x, b.y);
}

dvt iproduct(dot a, dot b)
{return a.x * b.x + a.y * b.y;}

dvt cross (dot a, dot b)
{return a.x * b.y - a.y * b.x;}

int side(line L, dot a){
dvt cross_value = cross(a-L.start, L.end-L.start);
if (cross_value > eps) {
return 1;
} else if (cross_value < -eps) {
return -1;
}
return 0;
}

bool has_jiao(line AB, line CD) {
int c = side(AB, CD.start);
int d = side(AB, CD.end);
// 0 代表在線上
if (c==0 || d==0) return true;
// 正負號不同=>異側=>相交
return c == -d;
}

