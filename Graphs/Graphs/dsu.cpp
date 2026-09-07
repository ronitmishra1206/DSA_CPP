class DSU
// basic DSU , optimization follows
{

public:
   int find(int i , vector<int>&parent){
    if(i==parent[i]){
    return i;
   }
   return find(parent[i],parent);
}
void unionn(int x , int y , vector<int>&parent){
    int x_parent = find(x,parent);
    int y_parent = find(y,parent);
    if(x_parent != y_parent){
        parent[x_parent] = y_parent;
    }
}
};



