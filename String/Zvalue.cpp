void z_value(string s){
	int L = 0, R = 0;
	z[0] = 0;
	for (int i = 1; i < (int)s.size(); i++){
		if (i > R)
        {
            z[i] = 0;
        }
        else{
			int ip = i - L;
			if (ip + z[ip] < z[L])
            {
                z[i] = z[ip];
            }
			else
            {
                z[i] = R - i + 1;
            } 
		}
		while (i + z[i] < (int)s.size() && s[i + z[i]] == s[z[i]])
        {
            z[i]++;
        }
		if (i + z[i] - 1 > R){
			L = i;
			R = L + z[i] - 1;
		}
	}
}
