int findd(int i, vector<int>& parent){ 
    if(i == parent[i]){
        return i;
    }

    return parent[i] = findd(parent[i], parent); // path compression
}

void uunion(int x, int y, vector<int>& parent, vector<int>& rank){ // union by rank

    int x_parent = findd(x, parent);
    int y_parent = findd(y, parent);

    if(x_parent == y_parent){
        return;
    }

    if(rank[x_parent] > rank[y_parent]){
        parent[y_parent] = x_parent;
    }
    else if(rank[y_parent] > rank[x_parent]){
        parent[x_parent] = y_parent;
    }
    else{
        parent[x_parent] = y_parent;
        rank[y_parent]++;
    }
}
