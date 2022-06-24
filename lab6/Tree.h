#pragma once
#include <iostream>
#include<string>
using namespace std;

class Node {
	double value;

	Node* right;
	Node* left;
	
public:
	Node(double);
	~Node();
	friend class Tree;
};

class Tree {
	Node* root;
	void add_node_rec(Node*& parent, double value);
	void print_rec(Node*& parent, int tabs);
	void average_num_rec(Node*& parent, double& sum, int& num);

public:
	Tree();
	~Tree();
	void add_node(double value);
	void print();
	double average_num();
	
};

double input();