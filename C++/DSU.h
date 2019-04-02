//
// Created by Hassan El Desouky on 2019-04-01.
//

#ifndef PST_DSU_H
#define PST_DSU_H


class DSU {
public:
    DSU(int n);
    void union_sets(int u, int v);
    bool same_set(int u, int v);
    ~DSU();
private:
    int find_parent(int u);
    void swap(int& a, int& b);
    int* parent;
    int* sz;
};


#endif //PST_DSU_H
