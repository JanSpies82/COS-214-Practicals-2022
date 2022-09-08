#include "IteratorManager.h"
#include "DirectoryIteratorFactory.h"
#include "FileIteratorFactory.h"
using namespace std;

IteratorManager::IteratorManager()
{
    factories = new IteratorFactory *[2];
    factories[0] = new DirectoryIteratorFactory();
    factories[1] = new FileIteratorFactory();
    currentIterator = NULL;
    node = NULL;
};

IteratorManager::~IteratorManager()
{
    delete factories[0];
    delete factories[1];
    delete[] factories;
    if (currentIterator != NULL)
        delete currentIterator;
};

void IteratorManager::setNode(Node *node)
{
    this->node = node;
    if (node->getType() == "Directory")
        currentIterator = factories[0]->createIterator(node);
    else
        currentIterator = factories[1]->createIterator(node);
}

void IteratorManager::first()
{
    if (currentIterator == NULL)
        __throw_runtime_error("Please set the node first");
    currentIterator->first();
};
void IteratorManager::next()
{
    if (currentIterator == NULL)
        __throw_runtime_error("Please set the node first");
    node = currentIterator->next();
    handle(node);
};
bool IteratorManager::hasNext()
{
    if (currentIterator == NULL)
        __throw_runtime_error("Please set the node first");
    return currentIterator->hasNext();
};
Node *IteratorManager::current()
{
    if (currentIterator == NULL)
        __throw_runtime_error("Please set the node first");
    node = currentIterator->current();
    return node;
};
void IteratorManager::handle(Node *n)
{
    n->visit();
    if (n->getType() == "Directory")
    {
        delete currentIterator;
        currentIterator = factories[0]->createIterator(n);
    }
    else
    {
        delete currentIterator;
        currentIterator = factories[1]->createIterator(n);
    }
};