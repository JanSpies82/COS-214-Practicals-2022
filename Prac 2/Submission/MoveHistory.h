#ifndef MOVEHISTORY_H
#define MOVEHISTORY_H
#include "Move.h"
#include <vector>
class MoveHistory
{
public:
    MoveHistory();
    ~MoveHistory();
    void addMove(Move* move);
    Move *getMove();

private:
    std::vector<Move *>* moves;
};
#endif // MOVEHISTORY_H