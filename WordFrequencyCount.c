#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MaxWordSize 20

typedef struct{
	char word[MaxWordSize +1];
	int wordCount;
}NodeData;

typedef struct treeNode{
	NodeData data;
	struct treeNode *left, *right;
}TreeNode, *TreeNodePtr;

typedef struct{
	TreeNodePtr root;
}BinaryTree;

int getWord(FILE* in, char str[]){
	char ch;
	int n=0;
	while(!isalpha(ch = getc(in)) && ch != EOF);
	if(ch == EOF){
		return 0;
	}
	str[n++] = tolower(ch);
	while(isalpha(ch = getc(in)) && ch != EOF)
		if(n < MaxWordSize){
			str[n++] = tolower(ch);
		}
	str[n] = '\0';
	return 1;
}

TreeNodePtr newTreeNode(NodeData d){
	TreeNodePtr p = (TreeNodePtr)malloc(sizeof(TreeNode));
	p->data = d;
	p->left = p->right = NULL;
	return p;
}

TreeNodePtr findOrInsert(BinaryTree bt, NodeData d){
	TreeNodePtr newTreeNode(NodeData);
	if(bt.root == NULL)
		return newTreeNode(d);
	TreeNodePtr curr = bt.root;
	int cmp;
	while((cmp = strcmp(d.word, curr-> data.word)) != 0){
		if(cmp < 0){
			if(curr->left == NULL){
				return curr->left = newTreeNode(d);
			}
			curr = curr->left;
		}
		else{
			if(curr->right == NULL){
				return curr->right = newTreeNode(d);
			}
			curr = curr->right;
		}
	}
	return curr;
}

void inOrder(TreeNodePtr node){
	if(node != NULL){
		inOrder(node->left);
		printf("%-15s %2d\n", node->data.word, node->data.wordCount);
		inOrder(node->right);
	}
}

NodeData newNodeData(char str[], int n){
	NodeData temp;
	strcpy(temp.word, str);
	temp.wordCount = n;
	return temp;
}

main() {
	int getWord(FILE *, char[]); 
	TreeNodePtr newTreeNode(NodeData);
	NodeData newNodeData(char[], int);
	TreeNodePtr findOrInsert(BinaryTree, NodeData);
	void inOrder(FILE *, TreeNodePtr);
	char word[MaxWordSize + 1];
	FILE* in = fopen("wordwordCount.in.txt", "r");
	FILE* out = fopen("wordwordCount.out.txt", "w");
	
	BinaryTree bst; 
	bst.root = NULL;
	while(getWord(in, word) != 0){
		if (bst.root == NULL) {
			bst.root = newTreeNode(newNodeData(word ,1));
		}
		else{
			TreeNodePtr node = findOrInsert(bst, newNodeData(word, 0));
			node -> data.wordCount++;
		}
	}
	printf("\nWords     Frequency\n\n");
	inOrder(bst.root);
	printf("\n\n");
	fclose(in);
	system("PAUSE");
}//end main
