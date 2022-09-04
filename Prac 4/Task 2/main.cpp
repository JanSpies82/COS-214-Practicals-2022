#include <iostream>
#include <string>
#include <ctime>
#include "Node.h"
#include "File.h"
#include "Directory.h"

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

void testFile()
{
    File *file1 = new File();
    File *file2 = new File("File2.txt");
    cout << "File1 name: " << file1->getName() << endl;
    cout << "File2 name: " << file2->getName() << endl;
    cout << "File1 last modified: " << file1->getLastModified() << " : " << file1->timeToString(file1->getLastModified());
    cout << "File2 last modified: " << file2->getLastModified() << " : " << file2->timeToString(file2->getLastModified());
    file1->setName("File11.txt");
    cout << "File1 name: " << file1->getName() << endl;
    cout << "File2 name: " << file2->getName() << endl;
    cout << "File1 last modified: " << file1->getLastModified() << " : " << file1->timeToString(file1->getLastModified());
    cout << "File2 last modified: " << file2->getLastModified() << " : " << file2->timeToString(file2->getLastModified());
    cout << "Is file1 last modified equal to file2 last modified? " << (file1->getLastModified() == file2->getLastModified() ? "Yes" : "No") << endl;
    cout << "File1 contents: " << file1->getContents() << endl;
    cout << "File2 contents: " << file2->getContents() << endl;
    file1->setContents("File1 contents");
    file2->setContents("File2 contents");
    cout << "File1 contents: " << file1->getContents() << endl;
    cout << "File2 contents: " << file2->getContents() << endl;
    cout << "File1 extension: " << file1->getExtension() << endl;
    cout << "File2 extension: " << file2->getExtension() << endl;
    file1->setExtension("txt");
    file2->setExtension("txt");
    cout << "File1 extension: " << file1->getExtension() << endl;
    cout << "File2 extension: " << file2->getExtension() << endl;
    cout << "File1 name: " << file1->getName() << endl;
    cout << "File2 name: " << file2->getName() << endl;
    file1->appendContents(" appended");
    file2->prependContents("prepended ");
    cout << "File1 contents: " << file1->getContents() << endl;
    cout << "File2 contents: " << file2->getContents() << endl;
    delete file1;
    delete file2;
}

void testDirectories(){

}

void runTests()
{
    // testNodes();
    // testFile();
}
int main()
{
    runTests();
    return 0;
}