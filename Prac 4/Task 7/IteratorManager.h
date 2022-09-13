#ifndef ITERATORMANAGER_H
#define ITERATORMANAGER_H
#include "NodeIterator.h"
#include "IteratorFactory.h"
class IteratorManager
{
public:
    IteratorManager();
    ~IteratorManager();
    void first();
    void next();
    bool hasNext();
    Node *current();
    void setNode(Node *node);

private:
    IteratorFactory **factories;
    NodeIterator *currentIterator;
    Node *node;
    void handle(Node* n);
};
#endif