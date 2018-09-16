bool match(int i) {
	vx[i] = true;
	for (int j = 1; j <= n; j++) {
		if ((fabs(Lx[i] + Ly[j] - w[i][j]) < 1e-9) && !vy[j]) {
			vy[j] = 1;
			if (!Left[j] || match(Left[j])) {
				Left[j] = i;
				return true;
			}
		}
	}
	return false;
}
void update() {
	double a = 1e30;
	for (int i = 1; i <= n; i++) {
		if (vx[i])for (int j = 1; j <= n; j++) {
				if (!vy[j])a = min(a, Lx[i] + Ly[j] - w[i][j]);
			}
	}
	for (int i = 1; i <= n; i++) {
		if (vx[i])Lx[i] -= a;
		if (vy[i])Ly[i] += a;
	}
}
void KM() {//reset lx ly left
	for (int i = 1; i <= n; i++) {
		while (1) {
			vx.reset(); vy.reset();
			if (match(i))break;
			update();
		}
	}
}