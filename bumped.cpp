#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <utility>
#include <math.h>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

typedef pair<int, int> pi;

struct edge {
    int weight;
    int dest;
    bool flight;
};


struct vertex {
    long long dist;
    long long  fdist;

    vector<edge> adj;
};


int main () {

    int ncities = 0, nroads =0, nflights = 0, start = 0, end =0;
    cin >> ncities >> nroads >> nflights >> start >> end;
    vertex fill;
    fill.dist = 1000000000000000;
    fill.fdist = 1000000000000000;
    vector<vertex> verticies(ncities, fill);
    for(int i =0; i < nroads; i++){
        int v1 = 0, v2 = 0, w =0;
        cin >> v1 >> v2 >> w;
        verticies[v1].adj.push_back({w,v2,false});
        verticies[v2].adj.push_back({w,v1,false});
    }
    for(int i = 0; i <nflights; i++){
        int v1 = 0, v2 = 0;
        cin >> v1 >> v2;
        verticies[v1].adj.push_back({0,v2,true});
    }

    priority_queue <pi, vector<pi>, greater<pi>> minq;
    verticies[start].dist = 0;
    minq.push({verticies[start].dist, start});
    while(!minq.empty()) {
        int curr = minq.top().second;
        minq.pop();
        for(auto i : verticies[curr].adj){
            if(i.flight){
                if(verticies[curr].dist < verticies[i.dest].fdist){
                    verticies[i.dest].fdist = verticies[curr].dist;
                    minq.push({verticies[i.dest].dist, i.dest});
                }
            }
            else{
                bool flag = false;
                if(verticies[curr].dist + i.weight < verticies[i.dest].dist){
                    verticies[i.dest].dist = verticies[curr].dist + i.weight;
                    flag = true;
                }
                if(verticies[curr].fdist + i.weight < verticies[i.dest].fdist){
                    verticies[i.dest].fdist = verticies[curr].fdist + i.weight;
                    flag = true;
                }
                if(flag){
                    minq.push({verticies[i.dest].dist, i.dest});
                }
            }
        }
    }
    
    cout << min(verticies[end].fdist, verticies[end].dist);

    return 0;
}