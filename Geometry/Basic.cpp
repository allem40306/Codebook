struct dot
{
    dvt x, y;
};
struct Line
{
    dot st, ed;
};

dot operator+(dot a, dot b) { return {a.x + b.x, a.y + b.y}; }
dot operator-(dot a, dot b) { return {a.x - b.x, a.y - b.y}; }
dot operator*(dot a, dvt c) { return {a.x * c, a.y * c}; }
dot operator*(dvt c, dot a) { return a * c; }
dot operator/(dot a, dvt c) { return {a.x / c, a.y / c}; }
bool operator<(dot a, dot b) { return std::tie(a.x, a.y) < std::tie(b.x, b.y); }
bool operator==(dot a, dot b)
{
    return std::tie(a.x, a.y) == std::tie(b.x, b.y);
}
dvt iproduct(dot a, dot b) { return a.x * b.x + a.y * b.y; }
dvt cross(dot a, dot b) { return a.x * b.y - a.y * b.x; }
int dis(dot a, dot b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int side(Line L, dot a)
{
    dvt cross_value = cross(a - L.st, L.ed - L.st);
    if (cross_value > EPS)
    {
        return 1;
    }
    else if (cross_value < -EPS)
    {
        return -1;
    }
    return 0;
}

bool has_jiao(Line AB, Line CD)
{
    int a = side(CD, AB.st);
    int b = side(CD, AB.ed);
    int c = side(AB, CD.st);
    int d = side(AB, CD.ed);
    if (a * b < 0 && c * d < 0)
    {
        return true;
    }
    if (a == 0 && iproduct(CD.st - AB.st, CD.ed - AB.st) <= 0)
    {
        return true;
    }
    if (b == 0 && iproduct(CD.st - AB.ed, CD.ed - AB.ed) <= 0)
    {
        return true;
    }
    if (c == 0 && iproduct(AB.st - CD.st, AB.ed - CD.st) <= 0)
    {
        return true;
    }
    if (d == 0 && iproduct(AB.st - CD.ed, AB.ed - CD.ed) <= 0)
    {
        return true;
    }
    return false;
}
