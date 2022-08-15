#include "MoveHistory.h"
using namespace std;

MoveHistory::MoveHistory()
{
    moves = new vector<Move *>();
};

MoveHistory::~MoveHistory()
{
    for (int i = 0; i < moves->size(); i++)
    {
        delete moves->at(i);
    }
    delete moves;
};
void MoveHistory::addMove(Move *move)
{
    moves->push_back(move);
};

Move *MoveHistory::getMove()
{
    if (moves->size() > 0)
    {
        Move *m = moves->back();
        moves->pop_back();
        return m;
    }
};