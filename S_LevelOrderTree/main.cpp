void S_LevelOrderPrint(TreeNode t){
    stack<TreeNode> s1;
    stack<TreeNode> s2;
    s1.push(t);
    while(!s1.empty() || !s2.empty()){
        if(!s1.empty()){
            while(!s1.empty()){
                TreeNode tn = s1.top();
                cout<<tn.val<<"";
                s1.pop();
                if(tn.right != null){s2.push(tn.right);}
                if(tn.left != null){s2.push(tn.left);}
            }
        }
        else{
            while(!s2.empty()){
                TreeNode tn = s2.top();
                cout<<tn.val<<" ";
                s2.pop();
                if(tn.left != null){s1.push(tn.left);}
                if(tn.right != null){s1.push(tn.right);}
            }
        }
	}
}
