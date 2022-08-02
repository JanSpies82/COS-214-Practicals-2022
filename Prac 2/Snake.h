#ifndef SNAKE_H
#define SNAKE_H
class Snake : public Enemy
{
public:
    bool hitSquadMember(Enemy *z);
    void celebrate();
    bool getHit(Enemy *z);
    void die();
};
#endif // SNAKE_H