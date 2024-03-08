func findCircleNum(isConnected [][]int) int {
    
    N := len(isConnected)
    visited := make([]bool, N)
    
    connected :=0
    
    for node:=0; node< N; node++{
        
        if !visited[node]{
            connected++
            visited[node] = true
            dfs(node, visited, isConnected)
        }
    }//for
    
    
    
    return connected
}


func dfs(node int, visited []bool, isConnected[][] int){
    
    for idx, neigh := range isConnected[node]{
        
        if neigh ==1 && visited[idx] ==false {
            
            visited[idx] = true
            dfs(idx, visited, isConnected)
        }
    }
}