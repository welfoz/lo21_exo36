#if !defined(_GRAPH_H)
#define _GRAPH_H
#include<list>
#include<vector>
#include<iostream>
#include<string>
using namespace std;

class GraphException : public exception {
    string info;
public:
    GraphException(const string& i) noexcept :info(i) {}
    virtual ~GraphException() noexcept {}
    const char* what() const noexcept { return info.c_str(); }
};


class Graph {
    vector<list<unsigned int> > adj;
    string name;
public:
    Graph(const string& n, size_t nb);
    const string& getName() const { return name;  }
    size_t getNbVertices() const { return adj.size(); }
    size_t getNbEdges() const;
    void addEdge(unsigned int i, unsigned int j);
    void removeEdge(unsigned int i, unsigned int j);
    const list<unsigned int>& getSuccessors(unsigned int i) const;
    const list<unsigned int> getPredecessors(unsigned int i) const;
};
ostream& operator<<(ostream& f, const Graph& G);
#endif
