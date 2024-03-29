istream &operator>>(istream &in, __int128 &x)
{
    char buf[30];
    in >> buf;
    bool minus = false;
    int len = strlen(buf);
    x = 0;
    for (int i = 0; i < len; i++)
    {
        if (i == 0 && buf[i] == '-')
        {
            minus = true;
        }
        else
        {
            x = x * 10 + buf[i] - 48;
        }
    }
    if (minus)
    {
        x *= -1;
    }
    return in;
}

ostream &operator<<(ostream &out, __int128 &x)
{
    vector<int> v;
    __int128 tmp = x;
    bool minus = tmp < 0;
    if (minus)
        tmp *= -1;

    while (tmp > 0)
    {
        v.push_back(tmp % 10);
        tmp /= 10;
    }
    if (minus)
    {
        out << "-";
    }
    for (int i = (int)v.size() - 1; i >= 0; i--)
    {
        out << v[i];
    }
    return out;
}