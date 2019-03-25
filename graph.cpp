#include "graph.h"
#include <iostream>

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
