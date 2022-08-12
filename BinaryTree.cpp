// BinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
using namespace std;

struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
	Node(int data)
	{
		this->data = data;
		left = right = nullptr;
	}
};

void PrintTree(const Node* node) {
	if (node->left) PrintTree(node->left);
	std::cout << node->data << "\n";
	if (node->right) PrintTree(node->right);
}

void ReverseBinaryTree(Node* node) {
	stack<Node*> stack;
	while (node || !stack.empty()) {
		while (node) {
			stack.push(node);
			node = node->left;
		}
		node = stack.top();
		stack.pop();
		Node* swap = node->right;
		node->right = node->left;
		node = node->left = swap;
	}
}

void RecursiveReverseBinaryTree(Node* node) {
	if (node->left) RecursiveReverseBinaryTree(node->left);
	Node* swap = node->right;
	node->right = node->left;
	node->left = swap;
	if (swap) RecursiveReverseBinaryTree(swap);
}

int main()
{
    std::cout << "Binary Tree\n";

	/* Constructed binary tree is
              1
		    /   \
          2      3
		/  \
      4     5
	*/
	struct Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);

	PrintTree(root);
	std::cout << "Reversing...\n";
	// ReverseBinaryTree(root);
	RecursiveReverseBinaryTree(root);
	std::cout << "Result\n";
	PrintTree(root);
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
