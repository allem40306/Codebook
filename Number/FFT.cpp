struct Complex
{
    LD r, i;
    Complex(LD _r = 0.0, LD _i = 0.0)
    {
        r = _r;
        i = _i;
    }
    Complex operator+(Complex rhs) { return Complex(r + rhs.r, i + rhs.i); }
    Complex operator-(Complex rhs) { return Complex(r - rhs.r, i - rhs.i); }
    Complex operator*(Complex rhs)
    {
        return Complex(r * rhs.r - i * rhs.i, r * rhs.i + i * rhs.r);
    }
};

template <typename T> struct FFT
{
    void fft(vector<Complex> &a, int n, int inv)
    {
        for (int i = 1, j = 0; i < n; ++i)
        {
            for (int k = (n >> 1); (j ^= k) < k; k >>= 1)
                ;
            if (i > j)
            {
                swap(a[i], a[j]);
            }
        }
        for (int m = 2; m <= n; m <<= 1)
        {
            Complex wm(cos(2 * PI * inv / m), sin(2 * PI * inv / m));
            for (int k = 0; k < n; k += m)
            {
                Complex w(1.0, 0.0);
                for (int j = 0; j < (m >> 1); ++j, w = w * wm)
                {
                    Complex u = a[k + j], t = w * a[k + j + (m >> 1)];
                    a[k + j] = u + t;
                    a[k + j + (m >> 1)] = u - t;
                }
            }
        }
        if (inv == -1)
        {
            FOR(i, 0, n)
            {
                a[i].r /= n;
                a[i].i /= n;
            }
        }
    }
    void convolution(vector<Complex> &A, vector<Complex> &B, vector<Complex> &C,
                     vector<Complex> &D, int n, vector<Complex> &ans)
    {
        fft(A, n, 1);
        fft(B, n, 1);
        fft(C, n, 1);
        fft(D, n, 1);
        FOR(i, 0, n) { ans[i] = A[i] * B[i] * C[i] * D[i]; }
        fft(ans, n, -1);
        return;
    }
};