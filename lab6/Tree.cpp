#include"Tree.h"

Node::Node(double val) {
	this->value = val;
	right = nullptr;
	left = nullptr;
}

Node::~Node() {
	delete right;
	delete left;
}

Tree::Tree() {
	root = nullptr;
}

Tree::~Tree() {
	delete root;
}

void Tree::add_node(double val) {
	add_node_rec(root, val);
}

void Tree::add_node_rec(Node*& parent, double val) {
	if (!parent) {
		parent = new Node(val);
		parent->left = nullptr;
		parent->right = nullptr;
		return;
	}
	else {
		if (parent->value < val)
			add_node_rec(parent->right, val);
		else if (parent->value >= val)
			add_node_rec(parent->left, val);
	}
}

void Tree::print() {
	print_rec(root, 0);
}

void Tree::print_rec(Node*& parent, int tabs) {
	for (int i = 0; i < tabs; i++)
	{
		cout << string(3, ' ') << '|';
	}
	cout << string(2, '_');
	if (parent != nullptr)
	{
		cout << parent->value << endl;

		print_rec(parent->right, tabs + 1);
		print_rec(parent->left, tabs + 1);
	}
	else
		cout << endl;
}

double Tree::average_num() {
	double sum = 0;
	int num = 0;
	average_num_rec(root, sum, num);
	double avg = sum / (double)num;
	return avg;

}

void Tree::average_num_rec(Node*& parent, double& sum, int& num) {
	if (parent) {
		sum += parent->value;
		num++;
		if (parent->left)
			average_num_rec(parent->left, sum, num);
		if (parent->right)
			average_num_rec(parent->right, sum, num);
	}
}

double input() {
	string s;
	double res;
	while (true)
	{
		try
		{
			cout << "Enter number: "; cin >> s;
			res = stod(s);
			break;
		}
		catch (const exception&)
		{
			cout << "Enter right number!!!!! \n";
		}
	}
	return res;
}