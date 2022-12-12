#include "graph.h"
#include <algorithm>

Graph::Graph(const string& n, size_t nb) :
    name(n),
    //adj(nb, list<unsigned int>())
    adj(nb) // par dÈfaut c'est
            // list<unsigned int>() qui est utilisÈ
{

}

size_t Graph::getNbEdges() const {
    size_t nbarcs = 0;
    //for (size_t i = 0; i < adj.size(); i++)
    //    nbarcs += adj[i].size();
    //for (auto it=adj.begin(); it!=adj.end(); ++it)
    //    nbarcs += it->size(); // (*it).size()
    for (auto& l : adj) nbarcs += l.size();
    return nbarcs;
}

void Graph::addEdge(unsigned int i, unsigned int j) {
    if (i >= adj.size() || j >= adj.size())
        throw GraphException("sommet inexistant");
    if (find(adj[i].begin(), adj[i].end(), j)
        != adj[i].end())
        throw GraphException("ajout arc deja existant");
    adj[i].push_back(j);
}

void Graph::removeEdge(unsigned int i, unsigned int j) {
    if (i >= adj.size() || j >= adj.size())
        throw GraphException("sommet inexistant");
    auto it = find(adj[i].begin(), adj[i].end(), j);
    if (it==adj[i].end())
        throw GraphException("elimination arc inexistant");
    adj[i].erase(it);
}

const list<unsigned int>& Graph::getSuccessors(unsigned int i) const {
    if (i >= adj.size())
        throw GraphException("sommet inexistant");
    return adj[i];
}
const list<unsigned int> Graph::getPredecessors(unsigned int i) const {
    list<unsigned int> pred;
    for (size_t j = 0; j < adj.size(); j++)
        if (find(adj[j].begin(), adj[j].end(), i)
            != adj[j].end())
            pred.push_back(j);
    return pred;
}

ostream& operator<<(ostream& f, const Graph& G) {
    f << "Graph " << G.getName() << "("
        << G.getNbVertices() << " vertices, "
        << G.getNbEdges() << " edges)";
    for (size_t i = 0; i < G.getNbVertices(); i++) {
        f << i << ":";
        for (auto& x : G.getSuccessors(i))
            f << x << ";";
        f << "\n";
    }
    return f;
}

