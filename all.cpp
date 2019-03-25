#include <iostream>
#include <cstdlib>

#define SIZE 5

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


List::List(){
	head = NULL;
}

bool List::isEmpty(){
	return (head == NULL);
}

Node* List::createNode(int data){
	Node* n = new Node;
	n->data = data;
	n->next = NULL;

	return n;
}

void List::insert(int data){
	if(!isEmpty()){
		Node* temp = head;
		while(temp->next) temp = temp->next;
		temp->next = createNode(data);
	}
	else{
		head = createNode(data);
	}
}

void List::display(){
	Node* temp = head;
	while(temp){
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
}


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

Graph::Graph(){
	head = NULL;
}

bool Graph::isEmpty(){
	return (head == NULL);
}



GraphNode* Graph::createNode(int v){
	GraphNode* n = new GraphNode;
	n->vertex = v;
	n->next = NULL;
	return n;
}

GraphNode* Graph::createNode(int v,int e){
	GraphNode* n = createNode(v);
	n->edges.insert(e);
	return n;
}
void Graph::insert(int v){
	if(!isEmpty()){
		GraphNode* temp = head;
		while(temp->next) temp = temp->next;
		temp->next = createNode(v);
	}
	else{
		head = createNode(v);
	}
}
void Graph::insert(int v,int e){
	if(!isEmpty()){
		GraphNode* temp = head;

		if(temp->vertex == v){
			temp->edges.insert(e);
		}else{
			while(temp->next && temp->vertex != v){
				temp = temp->next;
			}
			if (temp->vertex == v)
			{
				temp->edges.insert(e);
			}else{
				temp->next = createNode(v,e);
			}
		}
	}
	else{
		head = createNode(v,e);
	}
}

void Graph::display(){
	GraphNode* temp = head;
	std::cout << "Vertices" << "\tEdges\n";
	while(temp){
		std::cout << temp->vertex << "\t\t";
		temp->edges.display();
		temp = temp->next;
	}
	std::cout << std::endl;
}

int main(){
	
	Graph g;

	/*

	Hocam asagadaki sample data. sizde ayni sekilde her vertex ve edge bir numara verin. ornek a=0; yada Victor=1
	army = 6 , diane = 5 mesela.. Simdi list sekilde kurmak
	g.insert(1,6) = g.insert(victor,army) ; g.insert(1,5) = g.insert(victor,diane) vb.
	*/
	
	g.insert(25,90);g.insert(25,78);g.insert(25,80);g.insert(25,20);
	//g.insert(25,10);g.insert(25,90);g.insert(25,90);g.insert(25,90);
	//g.insert(25,90);g.insert(25,70);g.insert(25,80);g.insert(25,20);

	g.insert(38,67);g.insert(38,97);g.insert(38,37);
	g.insert(8,67);g.insert(8,97);g.insert(8,37);
	g.insert(50);g.insert(50,89);
	g.display();
	
	return 0;
}