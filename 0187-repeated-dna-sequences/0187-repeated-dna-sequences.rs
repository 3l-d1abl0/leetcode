use std::collections::HashMap;

impl Solution {
    pub fn find_repeated_dna_sequences(s: String) -> Vec<String> {
        
         if s.len() < 10 {
            return vec![];
        }
        
        let mut ans = Vec::new();
        
        let mut map = HashMap::new();
        
        for i in 0..s.len() - 9 {
            
            let str = &s[i..i + 10];  //(i to i+9)
            
            if let Some(freq) = map.get(str) {
                if *freq == 1 {
                    ans.push(str.to_string());
                }
            }

            *map.entry(str.to_string()).or_insert(0) += 1;
            
            
//             let count = map.entry(t).or_insert(0);
//             *count += 1;
//             if *count == 2 {
//                 ans.push(t.to_string());
//             }
        }
        ans
        
    }
}