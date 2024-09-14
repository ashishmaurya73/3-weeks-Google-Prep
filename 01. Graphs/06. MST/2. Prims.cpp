/*
	Notes:
	1- No self loop or parelled edges 
	2- We try to connect all the nodes 
	3- We start by picking 1 node 
	4- Then we select the smallest edge from this node 
	5- Now we have 2 nodes
	6- Now we select the min edge from these 2 nodes
	7- This way we keep including nodes and covers up all nodes
	8- In total we have V nodes and V-1 edges
	9- We use adj list 
	Time Complexity :- O((V+E)Log(V))
	Space Complexity :- O(E+V)

*/

#include<bits/stdc++.h>
using namespace std;

int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        vector<int> mst(V,0);
        vector<int> key(V,INT_MAX);
        vector<int> parent(V,-1);
        int ans=0;
        priority_queue<vector<int>> q;
        q.push({0,0});
        key[0]=0;
    
        while(q.size()) {
            int u = q.top()[1];
            mst[u]=1;
            q.pop();
            
            for(int v=0;v<V;v++) {
                if(v == u || mst[v] == 1 ) continue;
                int w = abs(points[u][0]-points[v][0]) + abs(points[u][1]-points[v][1]);
                if(w < key[v]) {
                    key[v] = w;
                    parent[v]=u;
                    q.push({-key[v],v});
                }
            }
        }

        for(auto &a:key) {
            ans+=a;
        }
        return ans;
    }

// MY SOLUTION
//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        //{wt, node}
        
        vector<bool>inMst(V, false);
        pq.push({0, 0});
        int sum=0;
        
        // Total= O(E*(logE+logE))=O(ElogE)
        while(!pq.empty()){ //O(E)
            auto p=pq.top();
            pq.pop();       //0(log(E))
            
            int wt  =p.first;
            int node=p.second;
            if(inMst[node]==true){
                continue;
            }
            
            inMst[node]=true;
            sum+=wt;

            for(auto &it: adj[node]){
                int neighbour   =it[0];
                int neighbour_wt=it[1];
                if(!inMst[neighbour] ){
                    pq.push({neighbour_wt, neighbour}); //(log(E))
                }
            }
            
        }
        return sum;
    }











