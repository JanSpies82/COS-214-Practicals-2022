#include "Node.h"
#include "Observer.h"
using namespace std;

Node::Node()
{
    name = "";
    lastModified = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
    synchronous = 1;
    visited = 0;
}

Node::Node(string name, bool synchronous, string type, Node *parent)
{
    this->name = name;
    lastModified = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
    this->synchronous = synchronous;
    this->type = type;
    this->parent = parent;
    visited = 0;
}

Node::~Node()
{
}

string Node::getName()
{
    return name;
}

void Node::setName(string name)
{
    this->name = name;
    lastModified = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
    ;
}

double Node::getLastModified()
{
    return lastModified;
}

string Node::timeToString(double time)
{
    time_t t = time;
    return ctime(&t);
}

bool Node::isSynchronous()
{
    return synchronous;
}

string Node::getType()
{
    return type;
}

Node *Node::getParent()
{
    return parent;
}

void Node::setParent(Node *parent)
{
    this->parent = parent;
}

bool Node::isVisited()
{
    return visited;
}

void Node::notify()
{
    observer->update();
}