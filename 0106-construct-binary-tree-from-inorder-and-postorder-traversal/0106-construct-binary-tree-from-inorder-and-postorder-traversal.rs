// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
use std::collections::HashMap;

impl Solution {
    pub fn build_tree(inorder: Vec<i32>, postorder: Vec<i32>) -> Option<Rc<RefCell<TreeNode>>> {
        
        let mut in_map : HashMap<i32, usize> = HashMap::new();
        
        for(idx, &val)  in inorder.iter().enumerate(){
            in_map.insert(val, idx);
        }
        
        let l_post =0;
        let r_post = postorder.len() as i32 -1;
        let l_in = 0;
        let r_in = postorder.len() as i32 -1;
        
        
        Solution::build(&postorder, l_post, r_post, &in_map, &inorder, l_in, r_in)
    }
    
    
    fn build(postorder: &Vec<i32>, l_post:i32, r_post: i32,
                        in_map: &HashMap<i32, usize>,
            inorder: &Vec<i32>, l_in: i32, r_in: i32) -> Option <Rc<RefCell<TreeNode>>>{
        
                
                if l_post > r_post || l_in > r_in{
                    return None;
                }
                
                let root_ele = postorder[r_post as usize];
                
                if let Some(&root_ele_idx) = in_map.get(&root_ele) {
                    
                    let noe = root_ele_idx as i32 - l_in;
                    
                    let mut root = TreeNode::new(root_ele);
                    
                    root.left = Solution::build(postorder, l_post, l_post+noe-1, in_map, inorder, l_in, root_ele_idx as i32-1);
                    root.right = Solution::build(postorder, l_post+noe, r_post-1, in_map, inorder, root_ele_idx as i32+1, r_in );
                    
                    
                    Some(Rc::new(RefCell::new(root)))
                }else{
                    None
                }
    }
}