//https://www.codingninjas.com/codestudio/problems/count-strongly-connected-components-kosaraju-s-algorithm_1171151?leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include<bits/stdc++.h>
using namespace std;
void dfs(int node,unordered_map<int,bool> &vis,stack<int> &st,unordered_map<int,list<int>> &adj){
	vis[node]=true;
	for(auto ngr:adj[node]){
		if(!vis[ngr]){
			dfs(ngr,vis,st,adj);
		}
	}
	//topological logic
	st.push(node);
}
void revDfs(int node,unordered_map<int,bool> &vis,unordered_map<int,list<int>> &transpose){
	vis[node]=true;
	for(auto ngr:transpose[node]){
		if(!vis[ngr]){
			revDfs(ngr,vis,transpose);
		}
	}
}
int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	//input
	int i;
	unordered_map<int,list<int>> adj;
	for(i=0;i<edges.size();i++){
		int u=edges[i][0];
		int v=edges[i][1];
		adj[u].push_back(v);
	}
	//topological sort 
	stack<int> st;
	unordered_map<int,bool> vis;
	for(i=0;i<v;i++){
		if(!vis[i]){
			dfs(i,vis,st,adj);
		}
	}
	//transpose the matrix
	unordered_map<int,list<int>> transpose;
	for(i=0;i<v;i++){
		vis[i]=0;//setting all the nodes to unvisited as the were marked in topo sort earlier
		for(auto ngr:adj[i]){
			transpose[ngr].push_back(i);
		}
	}
	//dfs on transpose matrix 
	int count=0;
	while(!st.empty()){
		int top=st.top();
		st.pop();
		if(!vis[top]){
			count++;
			revDfs(top,vis,transpose);
		}
	}
	return count;
}