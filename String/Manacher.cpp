void sol(char *s)
{
    int sz = strlen(s);
    si = 0;
    ss[si++] = '$';
    ss[si++] = '#';
    FOR(i, 0, sz)
    {
        ss[si++] = s[i];
        ss[si++] = '#';
    }
    ss[si++] = '_';
    int mx = 0, id = 0;
    FOR(i, 0, si)
    {
        if (mx > i)
        {
            ma[i] = min(ma[2 * id - i], mx - i);
        }
        else
        {
            ma[i] = 1;
        }
        while (ss[i + ma[i]] == ss[i - ma[i]])
        {
            ++ma[i];
        }
        if (i + ma[i] > mx)
        {
            id = i;
            mx = i + ma[i];
        }
    }
}