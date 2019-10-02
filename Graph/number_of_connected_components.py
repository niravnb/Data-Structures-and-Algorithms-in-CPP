
def adjacency(adj, u ,v):
    adj[u].append(v)
    adj[v].append(u)

def DFSUtil(adj, visited, s):
    visited[s] = True
    for j in range(len(adj[s])):
        if visited[adj[s][j]]==False:
            DFSUtil(adj, visited, adj[s][j])

def DFS(adj,V):
    visited=[False for i in range(V)]
    count=0
    for i in range(V):
        if visited[i] == False:
            DFSUtil(adj,visited,i)
            count+=1
    return count
                
if __name__ == '__main__':
    V=5
    adj = [[] for i in range(V)]
    
    adjacency(adj,1,0)
    adjacency(adj,2,3)
    adjacency(adj,3,4)
    
    print DFS(adj, V)
    
