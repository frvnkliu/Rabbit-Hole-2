#include <bits/stdc++.h>
using namespace std;

//Modified Tarjans


int getMaxVisitableWebpages(int N, int M, vector<int> A, vector<int> B) {
  // 1) Build original graph, dropping duplicate links
  vector<unordered_set<int>> adj(N);
  for (int i = 0; i < M; i++) adj[A[i]].insert(B[i]);

  // 2) Modified Tarjan's to get graph of SCC sizes
  vector<int> disc l


  return answer;
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

