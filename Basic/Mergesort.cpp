long long sol(int L, int R) {
	if (R - L <= 1)return 0;
	int M = (R + L) / 2;
	long long ans = sol(L, M) + sol(M, R);
	int i = L, j = M, k = L;
	while (i < M || j < R) {
		if (i >= M)
			buf[k] = arr[j++];
		else if (j >= R)
			buf[k] = arr[i++];
		else {
			if (arr[i]<=arr[j])
				buf[k] = arr[i++];
			else {
				buf[k] = arr[j++];
				ans += M - i;
			}
		}
		k++;
	}
	for (int k = L; k < R; k++) arr[k] = buf[k];
	return ans;
}