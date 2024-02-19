// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }

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
    pub fn build_tree(preorder: Vec<i32>, inorder: Vec<i32>) -> Option<Rc<RefCell<TreeNode>>> {
        
                let mut in_map: HashMap<i32, usize> = HashMap::new();

        // Create a mapping of values to their indices in the inorder array
        for (idx, &val) in inorder.iter().enumerate() {
            in_map.insert(val, idx);
        }

        let pre_left = 0;
        let pre_right = preorder.len().checked_sub(1).unwrap_or(0) as i32;
        let in_left = 0;
        let in_right = inorder.len().checked_sub(1).unwrap_or(0) as i32;

        Solution::build(
            &preorder,
            pre_left,
            pre_right,
            &in_map,
            &inorder,
            in_left,
            in_right,
        )
        
    }
    
    
    fn build(
        preorder: &Vec<i32>,
        pre_left: i32,
        pre_right: i32,
        in_map: &HashMap<i32, usize>,
        inorder: &Vec<i32>,
        in_left: i32,
        in_right: i32,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        if pre_left > pre_right || in_left > in_right {
            return None;
        }

        let root_ele = preorder[pre_left as usize];

        if let Some(&root_ele_idx) = in_map.get(&root_ele) {
            let noe = root_ele_idx as i32 - in_left;

            let mut root = TreeNode::new(root_ele);
            root.left = Solution::build(
                &preorder,
                pre_left + 1,
                pre_left + noe,
                in_map,
                inorder,
                in_left,
                root_ele_idx as i32 - 1,
            );
            root.right = Solution::build(
                &preorder,
                pre_left + noe + 1,
                pre_right,
                in_map,
                inorder,
                root_ele_idx as i32 + 1,
                in_right,
            );

            Some(Rc::new(RefCell::new(root)))
        } else {
            None
        }
    }


}