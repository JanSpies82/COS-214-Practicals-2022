#include <iostream>
#include <string>
#include <ctime>
#include <unistd.h>
#include "Node.h"

using namespace std;

const std::string RED = "\x1B[31m";
const std::string GREEN = "\x1B[32m";
const std::string YELLOW = "\x1B[33m";
const std::string BLUE = "\x1B[34m";
const std::string CYAN = "\x1B[36m";
const std::string RESET = "\x1B[0m";

void testNodes()
{
    Node *node1 = new Node();
    Node *node2 = new Node("Node2");
    cout << "Node1 name: " << node1->getName() << endl;
    cout << "Node2 name: " << node2->getName() << endl;
    cout << "Node1 last modified: " << node1->getLastModified() << " : " << node1->timeToString(node1->getLastModified()) << endl;
    cout << "Node2 last modified: " << node2->getLastModified() << " : " << node2->timeToString(node2->getLastModified()) << endl;
    node1->setName("Node11");
    cout << "Node1 name: " << node1->getName() << endl;
    cout << "Node2 name: " << node2->getName() << endl;
    cout << "Node1 last modified: " << node1->getLastModified() << " : " << node1->timeToString(node1->getLastModified()) << endl;
    cout << "Node2 last modified: " << node2->getLastModified() << " : " << node2->timeToString(node2->getLastModified()) << endl;
    cout << "Is node1 last modified equal to node2 last modified? " << (node1->getLastModified() == node2->getLastModified() ? "Yes" : "No") << endl;
    delete node1;
    delete node2;
}

void runTests()
{
    testNodes();
}
int main()
{
    runTests();
    return 0;
}