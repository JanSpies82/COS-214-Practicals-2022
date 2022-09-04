#include "Node.h"
using namespace std;

Node::Node()
{
    name = "";
    lastModified = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
}

Node::Node(string name)
{
    this->name = name;
    lastModified = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
    ;
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
