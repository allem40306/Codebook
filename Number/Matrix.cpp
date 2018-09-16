template<typename T,int N=2>
struct Mat {//Matrix
	unsigned long long v[N][N];
	Mat operator*(Mat b)const {
		Mat val;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				val.v[i][j] = 0;
				for (int k = 0; k < N; k++) {
					val.v[i][j] += v[i][k] * b.v[k][j];
				}
			}
		}
		return val;
	}
};