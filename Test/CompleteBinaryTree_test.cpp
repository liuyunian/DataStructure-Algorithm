#include "BinaryTree/CompleteBinaryTree.h"
#include "Test/TestHelper/BinaryTreeHelper.h"

int main(){
	CompleteBinaryTree<int> cbt = generate_complete_binary_tree_int(10);
	cbt.level_order();
	cbt.pre_order();
	cbt.in_order();
	cbt.post_order();

	return 0;
}