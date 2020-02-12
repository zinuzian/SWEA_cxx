#include <iostream>
#include <cstring>

using namespace std;
void preorder(int **tree, int idx){
    cout << idx+1 << " ";
    if(tree[idx][0] != -1){
        preorder(tree, tree[idx][0]);
    }
    if(tree[idx][1] != -1){
        preorder(tree, tree[idx][1]);
    }
    
}
void inorder(int **tree, int idx){
    
    if(tree[idx][0] != -1){
        inorder(tree, tree[idx][0]);
    }
    cout << idx+1 << " ";
    if(tree[idx][1] != -1){
        inorder(tree, tree[idx][1]);
    }
    
}
void postorder(int **tree, int idx){
    
    if(tree[idx][0] != -1){
        postorder(tree, tree[idx][0]);
    }
    if(tree[idx][1] != -1){
        postorder(tree, tree[idx][1]);
    }
    cout << idx+1 << " ";
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int **arr = new int*[n];
    for(int i=0;i<n;i++){
        arr[i] = new int[2];
        memset(arr[i], -1, sizeof(int)*2);
    }
    

    for(int i=0;i<n-1;i++){
        int s, e;
        cin >> s >> e;
        if(arr[s-1][0] != -1){
            arr[s-1][1] = e-1;
        }else{
            arr[s-1][0] = e-1;
        }
    }


    preorder(arr, 0); cout << endl;
    inorder(arr, 0); cout << endl;
    postorder(arr, 0); cout << endl;

    return 0;
}
