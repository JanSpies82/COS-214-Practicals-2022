#ifndef NODE_H
#define NODE_H
#include <string>
#include <chrono>
#include <stdexcept>

class Node
{
public:
    Node();
    Node(std::string name, bool synchronous, std::string type);
    virtual ~Node();
    std::string getName();
    void setName(std::string name);
    double getLastModified();
    std::string timeToString(double time);
    bool isSynchronous();
    std::string getType();

protected:
    std::string name;
    double lastModified;
    bool synchronous;
    std::string type;
};
#endif