func findRepeatedDnaSequences(s string) []string {
    
    if len(s) < 10 {
		return []string{}
	}
    
	ans := make([]string, 0)
    cache := make(map[string]int)
    
	for i := 0; i+9 <= len(s)-1; i++ {
        
		curr := string(s[i : i+10])
        
		if cache[curr] == 1 {
			ans = append(ans, curr)
		}
	
        cache[curr]++
	}
    
	return ans
    
}