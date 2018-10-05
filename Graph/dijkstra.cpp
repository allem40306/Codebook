void dijkstra(int s){
	//set vis[]=0 d[]=inf
	priority_quque<Node>pq;
	d[s]=0;
	p[s]=s;
	pq.push(Node(s,0));
	while(!pq.empty()){
		while(!pq.empty()&&vis[pq.top().p])pq.top();
		if(pq.empty())break;
		vis[pq.top().p]=1;
		Node k=pq.top(); pq.pop();
		for(auto t:v[k.p]){
			if(d[k.p]+w[k.p][t]<d[t]){
				d[t]=d[k.p]+w[k.p][t];
				p[t]=k.p;
				pq.push((Node){t,d[t]})
			}
		}
	}
}