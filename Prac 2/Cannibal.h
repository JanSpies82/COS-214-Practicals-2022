#ifndef CANNIBAL_H
#define CANNIBAL_H
class Cannibal : public Enemy
{
public:
    bool hitSquadMember(Enemy *z);
    void celebrate();
    bool getHit(Enemy *z);
    void die();
};
#endif // CANNIBAL_H