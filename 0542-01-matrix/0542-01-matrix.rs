use std::collections::VecDeque;

impl Solution {
    pub fn update_matrix(mat: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let m = mat.len();
        let n = mat[0].len();
        let mut queue = VecDeque::new();
        let max_value = m * n as usize;
        let mut result = mat.clone();
        
        for i in 0..m {
            for j in 0..n {
                if mat[i][j] == 0 {
                    queue.push_back((i, j));
                } else {
                    result[i][j] = max_value as i32;
                }
            }
        }
        
        let directions = [(1, 0), (-1, 0), (0, 1), (0, -1)];
        
        while let Some((row, col)) = queue.pop_front() {
            for (dr, dc) in &directions {
                let r = row as i32 + dr;
                let c = col as i32 + dc;
                if r >= 0 && r < m as i32 && c >= 0 && c < n as i32 && result[r as usize][c as usize] > result[row][col] + 1 {
                    queue.push_back((r as usize, c as usize));
                    result[r as usize][c as usize] = result[row][col] + 1;
                }
            }
        }
        
        result
    }
}