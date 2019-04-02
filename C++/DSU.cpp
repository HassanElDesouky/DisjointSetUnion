//
// Created by Hassan El Desouky on 2019-04-01.
//

#include "DSU.h"

int DSU::find_parent(int u) {
    if(parent[u] == u)  return u;
    return parent[u] = find_parent(parent[u]);
}

void DSU::swap(int& a, int& b) {
    int c = a;
    a = b;
    b = c;
}

DSU::DSU(int n){
    parent = new int[n];
    sz = new int[n];
    for(int i = 0 ; i < n ; ++i) {
        parent[i] = i;
        sz[i] = 1;
    }
}

DSU::~DSU(){
    delete [] parent;
}

void DSU::union_sets(int u, int v) {
    u = find_parent(u);
    v = find_parent(v);
    if(sz[u] > sz[v]) swap(u, v);
    parent[u] = v;
    sz[v] += sz[u];
}

bool DSU::same_set(int u, int v) {
    return find_parent(u) == find_parent(v);
}
