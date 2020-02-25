#include "BinaryTree/BinaryTree.h"
#include "Test/TestHelper/BinaryTreeHelper.h"

int main(){
	BinaryTree<int> bt = generate_binary_tree_int("1,2,3,$,$,4,5,$,$,$,$,");	// test copy ctor
	bt.print();

	bt.pre_order();																														// test pre_order
	bt.pre_order_recursive();																									// test pre_order_recursive

	bt.in_order();																														// test in_order
	bt.in_order_recursive();																									// test in_order_recursive

	bt.post_order();																													// test post_order
	bt.post_order_recursive();																								// test post_order_recursive

	bt.level_order();																													// test level_order

	return 0;
}