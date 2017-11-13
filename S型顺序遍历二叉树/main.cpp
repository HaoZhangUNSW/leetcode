void SLevelOrderTraverse(TreeNode t){
	stack<TreeNode> s1;
	stack<TreeNode> s2;
	s1.push(t);
	while(!s1.empty() || !s2.empty()){
		if(!s1.empty()){
			while(!s1.empty()){
				TreeNode tn = s1.top();
				cout << tn.val << endl;
				s1.pop();
				if(tn.right != NULL){
					s2.push(tn.right);
				}
				if(tn.left != NULL){
					s2.push(tn.left);
				}
			
			}
		}
		if(!s2.emtpy()){
			while(!s2.empty()){
				TreeNode tn = s2.top();
				cout << tn.val << endl;
				if(tn.left != NULL){
					s1.push(tn.left);
				}
				if(tn.right != NULL){
					s1.push(tn.right);
				}			
			}
		}
	}
}
