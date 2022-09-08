#include <iostream>
#include <string>
#include <ctime>
#include <stdexcept>

#include "Node.h"
#include "File.h"
#include "AsynchronousDirectory.h"
#include "SynchronousDirectory.h"

#include "IteratorManager.h"
#include "NodeIterator.h"
#include "FileIterator.h"
#include "DirectoryIterator.h"

using namespace std;

const std::string RED = "\x1B[31m";
const std::string GREEN = "\x1B[32m";
const std::string YELLOW = "\x1B[33m";
const std::string BLUE = "\x1B[34m";
const std::string CYAN = "\x1B[36m";
const std::string RESET = "\x1B[0m";

// void testNodes()
// {
//     Node *node1 = new Node();
//     Node *node2 = new Node("Node2", false, "Node");
//     cout << "Node1 name: " << node1->getName() << endl;
//     cout << "Node2 name: " << node2->getName() << endl;
//     cout << "Node1 last modified: " << node1->getLastModified() << " : " << node1->timeToString(node1->getLastModified()) << endl;
//     cout << "Node2 last modified: " << node2->getLastModified() << " : " << node2->timeToString(node2->getLastModified()) << endl;
//     node1->setName("Node11");
//     cout << "Node1 name: " << node1->getName() << endl;
//     cout << "Node2 name: " << node2->getName() << endl;
//     cout << "Node1 last modified: " << node1->getLastModified() << " : " << node1->timeToString(node1->getLastModified()) << endl;
//     cout << "Node2 last modified: " << node2->getLastModified() << " : " << node2->timeToString(node2->getLastModified()) << endl;
//     cout << "Is node1 last modified equal to node2 last modified? " << (node1->getLastModified() == node2->getLastModified() ? "Yes" : "No") << endl;
//     delete node1;
//     delete node2;
// }

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

void testAsynchronousDirectory()
{
    Directory *adir1 = new AsynchronousDirectory("adir1");
    Directory *adir2 = new AsynchronousDirectory("adir2");

    cout << "adir1 name: " << adir1->getName() << endl;
    cout << "adir2 name: " << adir2->getName() << endl;

    Node *n11 = new File("n11.txt");
    Node *n12 = new File("n12.txt");
    Node *n21 = new File("n21.txt");
    Node *n22 = new File("n22.txt");

    adir1->addChild(n11);
    adir1->addChild(n12);
    adir2->addChild(n21);
    adir2->addChild(n22);

    cout << "adir1 contents: " << endl
         << adir1->listContents();
    cout << "adir2 contents: " << endl
         << adir2->listContents();

    try
    {
        adir1->removeChild("n.txt");
        cout << RED << "Error: No exception thrown when removing non-existent child" << RESET << endl;
    }
    catch (invalid_argument &e)
    {
        cout << GREEN << "Caught correct exception" << RESET << endl;
    }
    catch (...)
    {
        cout << RED << "Error: Wrong exception thrown when removing non-existent child" << RESET << endl;
    }

    try
    {
        adir1->removeChild("n11.txt");
        cout << GREEN << "Removed child" << RESET << endl;
    }
    catch (...)
    {
        cout << RED << "Error: Exception thrown when removing existing child" << RESET << endl;
    }

    SynchronousDirectory *sd = new SynchronousDirectory("sd");
    try
    {
        adir1->addChild(sd);
        cout << RED << "Error: No exception thrown when adding child of wrong type" << RESET << endl;
    }
    catch (invalid_argument &e)
    {
        cout << GREEN << "Caught correct exception" << RESET << endl;
    }
    catch (...)
    {
        cout << RED << "Error: Wrong exception thrown when adding child of wrong type" << RESET << endl;
    }

    delete adir1;
    delete adir2;
    delete sd;
}

void testSynchronousDirectory()
{
    Directory *sdir1 = new SynchronousDirectory("sdir1");
    Directory *sdir2 = new SynchronousDirectory("sdir2");

    cout << "sdir1 name: " << sdir1->getName() << endl;
    cout << "sdir2 name: " << sdir2->getName() << endl;

    Node *n11 = new File("n11.txt");
    Node *n12 = new File("n12.txt");
    Node *n21 = new File("n21.txt");
    Node *n22 = new File("n22.txt");

    sdir1->addChild(n11);
    sdir1->addChild(n12);
    sdir2->addChild(n21);
    sdir2->addChild(n22);

    cout << "sdir1 contents: " << endl
         << sdir1->listContents();
    cout << "sdir2 contents: " << endl
         << sdir2->listContents();

    try
    {
        sdir1->removeChild("n.txt");
        cout << RED << "Error: No exception thrown when removing non-existent child" << RESET << endl;
    }
    catch (invalid_argument &e)
    {
        cout << GREEN << "Caught correct exception" << RESET << endl;
    }
    catch (...)
    {
        cout << RED << "Error: Wrong exception thrown when removing non-existent child" << RESET << endl;
    }

    try
    {
        sdir1->removeChild("n11.txt");
        cout << GREEN << "Removed child" << RESET << endl;
    }
    catch (...)
    {
        cout << RED << "Error: Exception thrown when removing existing child" << RESET << endl;
    }

    AsynchronousDirectory *ad = new AsynchronousDirectory("ad");
    try
    {
        sdir1->addChild(ad);
        cout << GREEN << "Can add Async directories" << RESET << endl;
    }
    catch (...)
    {
        cout << RED << "Error: Exception thrown when adding Async directory" << RESET << endl;
    }

    // Node *n = new Node("n", 0, "");
    // try
    // {
    //     sdir1->addChild(n);
    //     cout << RED << "Error: No exception thrown when adding child of wrong type" << RESET << endl;
    // }
    // catch (invalid_argument &e)
    // {
    //     cout << GREEN << "Caught correct exception" << RESET << endl;
    // }
    // catch (...)
    // {
    //     cout << RED << "Error: Wrong exception thrown when adding child of wrong type" << RESET << endl;
    // }

    if (sdir2->access("n21.txt")->getName() != "n21.txt")
    {
        cout << RED << "Error: Accessing child by name failed" << RESET << endl;
    }
    else
    {
        cout << GREEN << "Accessing child by name succeeded" << RESET << endl;
    }

    delete sdir1;
    delete sdir2;
    // delete n;
}

void testDirectoryTask3()
{
    Directory *root = new SynchronousDirectory("Root");
    Directory *d11 = new SynchronousDirectory("d11");
    Directory *d12 = new AsynchronousDirectory("d12");
    Directory *d21 = new AsynchronousDirectory("d21");
    Directory *d31 = new AsynchronousDirectory("d31");
    Directory *d32 = new AsynchronousDirectory("d32");

    d21->addDirectory(d31);
    d21->addDirectory(d32);

    d11->addFile(new File("f21.txt"));
    d11->addDirectory(d21);

    d12->addFile(new File("f22.txt"));

    root->addDirectory(d11);
    root->addFile(new File("f11.txt"));
    root->addFile(new File("f12.txt"));
    root->addDirectory(d12);

    cout << "Does root contain a directory? " << root->listDirectory() << endl;
    cout << "Does root contain a file? " << root->listFile() << endl;
    cout << "Does d11 contain a directory? " << d11->listDirectory() << endl;
    cout << "Does d11 contain a file? " << d11->listFile() << endl;
    cout << "Does d12 contain a directory? " << d12->listDirectory() << endl;
    cout << "Does d12 contain a file? " << d12->listFile() << endl;
    cout << "Does d21 contain a directory? " << d21->listDirectory() << endl;
    cout << "Does d21 contain a file? " << d21->listFile() << endl;

    cout << "root contents: " << endl;
    cout << root->print() << endl;

    cout <<"Now removing directory d32" << endl;
    d21->removeDirectory("d32");

    cout << "root contents: " << endl;
    cout << root->print() << endl;

    cout <<" Now removing file f11.txt" << endl;
    root->removeFile("f11.txt");

    cout << "root contents: " << endl;
    cout << root->print() << endl;

    delete root;
}

void testBasicIterators()
{
    Directory *root = new SynchronousDirectory("Root");
    Directory *d11 = new SynchronousDirectory("d11");
    Directory *d12 = new AsynchronousDirectory("d12");
    Directory *d21 = new AsynchronousDirectory("d21");
    Directory *d31 = new AsynchronousDirectory("d31");
    Directory *d32 = new AsynchronousDirectory("d32");

    d21->addDirectory(d31);
    d21->addDirectory(d32);

    d11->addFile(new File("f21.txt"));
    d11->addDirectory(d21);

    d12->addFile(new File("f22.txt"));

    root->addDirectory(d11);
    root->addFile(new File("f11.txt"));
    root->addFile(new File("f12.txt"));
    root->addDirectory(d12);

    cout << "Root contents: " << endl;
    cout << root->print();

    cout << "Traversing the tree using the iterator" << endl;
    IteratorManager *it = root->createIteratorManager();
    it->first();
    while (it->hasNext())
    {
        Node *n = it->current();
        cout << n->getName() << endl;
        it->next();
    }

    Node *n = it->current();
    cout << n->getName() << endl;

    delete it;
    delete root;
}

void runTests()
{
    //* Task 2 tests
    // testFile();
    // testAsynchronousDirectory();
    // testSynchronousDirectory();

    //* Task 3 tests
    testDirectoryTask3();
    // testBasicIterators();
}
int main()
{
    runTests();
    return 0;
}