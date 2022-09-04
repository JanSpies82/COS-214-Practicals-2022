#ifndef NODE_H
#define NODE_H
#include <string>
#include <chrono>

class Node
{
public:
    Node();
    Node(std::string name);
    virtual ~Node();
    std::string getName();
    void setName(std::string name);
    double getLastModified();
    std::string timeToString(double time);

protected:
    std::string name;
    double lastModified;
};
#endif