void preprocess() {
	for (int i = 1; i <= 25; i++) {
		for (int j = 1; j <= n; j++) {
			if (par[j][i - 1] == -1 || par[par[j][i - 1]][i - 1] == -1)continue;
			par[j][i] = par[par[j][i - 1]][i - 1];
		}
	}
}