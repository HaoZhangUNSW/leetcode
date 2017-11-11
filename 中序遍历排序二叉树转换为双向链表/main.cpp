typedef struct node{
	struct node* left, *right;
}node;

void doeverything(node* root, node** lmost, node** rmost){
	node** llm=(node**)malloc(sizeof(node*));
	node** lrm=(node**)malloc(sizeof(node*));
	if(root->left) { 
			doeverything(root->left, llm, lrm);
			root->left=*lrm, root->left->right=root;
			*lmost=*llm;
	}else{
			*lmost=root;
	} 
		
	if(root->right) { 
			doeverything(root->right, llm, lrm);
			root->right=*llm, root->right->left=root;
			*rmost=*lrm;
	 }else{
		*rmost=root;
	 }
}
