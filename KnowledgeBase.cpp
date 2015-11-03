
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Vertex{

public:
	//constructor
	Vertex(){
		name = "";
		//neighborVector.clear();
		neighborVector.reserve(20000);
	}
	Vertex(string input){
		name = input;
		//initilizing vector
		//neighborVector.clear();
		neighborVector.reserve(20000);
	}

	//accessor methods
	string getName();
	vector<string> getNeighborVector();

	bool isNeighbor(string name);
	void print();
	void printNeighbor();
private:
	string name;
	vector<string> neighborVector;
};

//implementation of methods--------------------------
string Vertex::getName(){
	return name;
}
vector<string> Vertex::getNeighborVector(){
	return neighborVector;
}

void Vertex::print(){
	cout << name;
}

void Vertex::printNeighbor(){
	for (int i = 0; i < neighborVector.size(); i ++){
		cout << neighborVector[i];
		cout << "1" << endl;
	}
	cout << "1" << endl;
}

bool Vertex::isNeighbor(string name){
	for(int i = 0; i < neighborVector.size(); i++){
		if(neighborVector[i] == name){
			return true;
		}
	}
	return false;
}
class Graph{
public:
	//constructor
	Graph(){
		//initilizing vector
		adj_List.clear();
		adj_List.reserve(20000);
		//listSize = adj_List.size();
	}


	//accessor methods
	//Vertex *getRoot();
	int getSize();
	vector <Vertex*> getAdjList();
	//print method
	void print();
	void insert(string &);
	void insert(vector<string> v);//append vertex to the end of list
	int search(string name);//find if item exist in list, if yes, return index, other wise return null
	Vertex* mostDiversed();
	Vertex* findCommomAncestor(Vertex *, Vertex *);
private:
	vector <Vertex*> adj_List;
	//int listSize;


};
//implementation of methods--------------------------
int Graph::getSize(){
	return adj_List.size();
}
vector <Vertex*> Graph::getAdjList(){
	return adj_List;
}
void Graph::print(){
	Vertex *temp;
	for (int i = 0; i < adj_List.size(); i++){
		temp = adj_List[i];
		temp->print();
		cout << ":";
		temp->printNeighbor();
	}
}
int Graph::search(string name){
	//search for vertex, if not found, return -1
	for (int i = 0; i < adj_List.size(); i++){
		if (adj_List[i]->getName() == name){
			return i;
		}
	}
	return -1;
}
void Graph::insert(string & s){
	if(search(s) == -1){// if s is no in list, push it in.
		this->adj_List.push_back(new Vertex(s));
	}
	else {
		cout << s << "already in list" << endl;
	}
}
void Graph::insert(vector<string> v){
	int pIndex;
	//make sure each SP is in adjList
	for(int i = 0; i < v.size(); i ++){
		/*if(search(s) == -1){ //if not found in adj_list, add it
			this->adj_List.push_back(new Vertex(s));
		}*/
		if(search(v[i]) == -1){
			insert(v[i]);
		}
	}

	pIndex = search(v[0]);//index of first item in v which is parent
	cout <<"pindex: "<< pIndex << endl;
	vector<string> *v2 = NULL;
	
	for ( int i = 1; i < v.size(); i ++){//add rest items in to parent's neighbor list\
		//vector<string> *v2 = NULL;
	std::vector<string> v3 = adj_List[pIndex]->getNeighborVector();
	v2 = &v3;
		cout <<"size before: "<< v2->size() << endl;
		v2->push_back(v[i]);
		cout <<"size after: "<< v2->size() << endl;
	}
	//adj_List[pIndex]->getNeighborVector() = v3;
}
//traverse though adj_List and count how many neighbors each vertex has
//return vertex with max number of neighbors
Vertex* Graph::mostDiversed(){
	int max = 0;
	int index = 0;
	int temp;
	for (int i = 0; i < adj_List.size(); i++){
		temp = adj_List[i]->getNeighborVector().size();
		if(temp > max){
			max = temp;
			index = i;
		}
	}
	return adj_List[index];
}
/*
Vertex * findCommomAncestor(Vertex *v1, Vertex *v2){
	Vertex *temp;
	for(int i = 0; i < adj_List.size(); i ++){
		temp = adj_List[i];
		if(temp->isNeighbor(v1.getName()) &&  temp->isNeighbor(v2.getName())){
			return adj_List[search(v1)];
		}
	}
}

*/

int main()
{
	//build input vector
	std::vector<string> v;
	string a = "a";
	string b = "b";
	string c = "c";
	v.push_back(a);
	v.push_back(b);
	v.push_back("d");
	
	Graph *g = new Graph();
	//g->insert(a);
	//g->insert(b);
	//g->print();
	g->insert(v);
	g->getAdjList()[0]->getNeighborVector().push_back(a);
	g->print();
	cout << "size:"<<g->getAdjList().size() << endl;
	cout << g->getAdjList()[0]->getNeighborVector().size() << endl; 
	//cout << "hha" << endl;
}

