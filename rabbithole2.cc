#include <bits/stdc++.h>
using namespace std;

//All relevant vertex properties
struct vProp {
    int index;
    int lowlink;
    int visitable;
    vProp() : index(0), lowlink(0), visitable(0) {}
};

/*Modified Tarjans
  Returns number of visitable pages for a given vertex v
*/
int getVisitableWebpages(int v, int& index, vector<vProp>& vProps, stack<int>& S,  vector<unordered_set<int>>& adj){
  //Lots of pass by reference variables, idk if this is good practice
  vProps[v].index = vProps[v].lowlink = index++;
  int currMax = 0; //max visitable of descendents
  int start = S.size();
  S.push(v);
  for(int w : adj[v]){
    if(!vProps[w].index){
      currMax = max(currMax, getVisitableWebpages(w, index, vProps, S, adj));
      vProps[v].lowlink = min(vProps[v].lowlink, vProps[w].lowlink);
    }else if(!vProps[w].visitable){ //equivalent to being on stack since vProps[w].index != 0
      vProps[v].lowlink = min(vProps[v].lowlink, vProps[w].index);
    }else{
      currMax = max(currMax, vProps[w].visitable);
    }
  }
  if(vProps[v].lowlink == vProps[v].index){
    //Update all nodes in current SCC
    int currVisitable = currMax + S.size()-start;//visitable from current cycle
    while(S.top() != v){
      vProps[S.top()].visitable =  currVisitable;
      S.pop();
    }
    S.pop();
    vProps[v].visitable = currVisitable;
  }
  return vProps[v].visitable;
}

int getMaxVisitableWebpages(int N, int M, vector<int> A, vector<int> B) {
  // 1) Build original graph, dropping duplicate links

  vector<unordered_set<int>> adj(N);

  //Shift page numbering by 1 for better indexing
  for (int i = 0; i < M; i++) adj[A[i]-1].insert(B[i]-1);

  // 2) Modified Tarjan's
  int res = 0;
  int index = 1;
  vector<vProp> vProps(N); //vertex properties
  stack<int> S; //Stack
  for(int v = 0; v < N; v++){
    if(!vProps[v].index){
      res = max(res, getVisitableWebpages(v, index, vProps, S, adj));
    }
  }
  return res;
} 

int main(){
  int N, M;
  cin >> N >> M;
  vector<int> A(M), B(M);
  for(int i = 0; i < M; i++){
    cin >> A[i];
  }

  for(int i = 0; i < M; i++){
    cin >> B[i];
  }

  cout << getMaxVisitableWebpages(N, M, A, B) <<endl;
}

