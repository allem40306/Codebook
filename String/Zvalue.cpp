void z_value(){
	int lens = s.size(), l = 0, r = 0;
	z[0] = 0;
	for (int i = 1; i < lens; i++){
		if (i>r)z[i] = 0;
		else{
			int ip = i - l;
			if (ip + z[ip] < z[l])z[i] = z[ip];
			else z[i] = r - l + 1;
		}
		while (i + z[i] < lens&&s[i + z[i]] == s[z[i]])z[i]++;
		if (i + z[i] - 1 > r){
			l = i;
			r = l + z[i] - 1;
		}
	}
}