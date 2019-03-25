#ifndef Graph_H
#define Graph_H 

struct Node
{
	int data;
	Node* next;
};

class List
{
private:
	Node* head;
	Node* createNode(int);
	bool isEmpty();
public:
	List();
	void insert(int);
	void display();
};
struct GraphNode
{
	int vertex;
	List edges;
	GraphNode* next;
};

class Graph
{
	GraphNode* head;
	GraphNode* createNode(int,int);
	GraphNode* createNode(int);
	bool isEmpty();
public:
	Graph();
	void insert(int);
	void insert(int,int);
	void display();
};

#endif