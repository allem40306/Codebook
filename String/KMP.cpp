void bulid_fail_funtion(string B, int *fail){
	int len = B.length(), current_pos;
	current_pos = fail[0] = -1;
	for (int i = 1; i<len; i++){
		while (current_pos != -1 && B[current_pos + 1] != B[i]){
			current_pos = fail[current_pos];
		}
		if (B[current_pos + 1] == B[i])current_pos++;
		fail[i] = current_pos;
	}
}
void match(string A, string B, int *fail){
	int lenA = A.length(), lenB = B.length();
	int current_pos = -1;
	for (int i = 0; i<lenA; i++){
		while (current_pos != -1 && B[current_pos + 1] != A[i]){
			current_pos = fail[current_pos];
		}
		if (B[current_pos + 1] == A[i])current_pos++;
		if (current_pos == lenB - 1){//match! A[i-lenB+1,i]=B
			current_pos = fail[current_pos];
		}
	}
}
int main(){
	int t, i;
	string s;
	for (i = 0, cin >> t; i<t; i++){
		cin >> s;
		int fail[N];
		bulid_fail_funtion(s, fail);
		int p = s.length() - 1;
		if (fail[p] != -1 && (p + 1) % (p - fail[p]) == 0)printf("%d\n", p - fail[p]);
		else printf("%d\n", p + 1);
	}
}