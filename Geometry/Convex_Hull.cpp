vector<dot> p, p1;

void convexhull()
{
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    p1.clear();
    p1.resize(p.size());
    int m = 0;
    FOR(i, 0, p.size())
    {
        while (m > 1 && cross(p1[m - 1] - p1[m - 2], p[i] - p1[m - 2]) <= 0)
            m--;
        p1[m++] = p[i];
    }
    int k = m;
    FORD(i, p.size() - 2, 0 - 1)
    {
        while (m > k && cross(p1[m - 1] - p1[m - 2], p[i] - p1[m - 2]) <= 0)
            m--;
        p1[m++] = p[i];
    }
    if (m > 1)
        m--;
    p1.resize(m);
}