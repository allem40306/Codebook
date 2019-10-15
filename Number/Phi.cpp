void phi_table(int n)
{
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (phi[i])
            continue;
        for (int j = i; j < n; j += i)
        {
            if (!phi[j])
                phi[j] = j;
            phi[j] = phi[j] / i * (i - 1);
        }
    }
}