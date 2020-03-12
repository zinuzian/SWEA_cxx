#include <iostream>



using namespace std;


int parent[9], Rank[9];

void make_set(int x){
    parent[x] = x;
    Rank[x] = 0;
}
int find_set(int x){
    if(x != parent[x]) parent[x] = find_set(parent[x]);
    return parent[x];
}

void link(int x, int y){
    if(Rank[x] > Rank[y]){
        parent[y] = x;
    }else{
        parent[x] = y;
        if(Rank[x] == Rank[y]){
            Rank[y]++;
        }
    }
}

void Union(int x, int y){
    link(find_set(x),find_set(y));
}

void print_p(){
    for(int i=1;i<9;i++){
        cout << parent[i] << " ";
    }cout << endl;
}

void print_r(){
    for(int i=1;i<9;i++){
        cout << Rank[i] << " ";
    }cout << endl;
}

void check(){
    print_p(); 
    print_r();
    cout << endl;
}
int main(int argc, char const *argv[])
{
    for(int i=1;i<9;i++){
        make_set(i);
    }
    check(); 
    Union(1,3); check();
    Union(2,3); check();
    Union(5,6); check();
    Union(6,8); check();
    Union(1,5); check();
    Union(6,7); check();
    int n1 = find_set(4);
    int n2 = find_set(5);
    cout << n1 << " " << n2 << endl;
    
    print_p();
    print_r();
    return 0;
}

