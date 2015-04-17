#ifndef GAME_H
#define GAME_H
#include "appstate.h"
#include "../objects/object.h"
#include "../objects/player.h"
#include "../objects/enemy.h"
#include "../objects/bullet.h"
#include "../objects/brick.h"
#include "../objects/eagle.h"
#include <vector>
#include <string>

class Game : public AppState
{
public:
    Game();
    ~Game();
    void draw();
    void update(Uint32 dt);
    void eventProces(SDL_Event* ev);
    void loadLevel(std::string path);
    bool finished() const;
    AppState* nextState();

private:
    void clearLevel();

    void checkCollisionTankWithLevel(Tank* tank, Uint32 dt);
    void checkCollisionTwoTanks(Tank* tank1, Tank* tank2, Uint32 dt);
    void checkCollisionBulletWithLevel(Bullet* bullet);
    void checkCollisionBulletWithTanks(Bullet* bullet, Tank* tank);
    void checkCollisionTwoBullets(Bullet* bullet1, Bullet* bullet2);

    std::string uIntToString(unsigned num);
    void nextLevel();

    int m_level_columns_count;
    int m_level_rows_count;
    std::vector< std::vector <Object*> > m_level; //level bez krzaków
    std::vector<Object*> m_bushes;

    std::vector<Enemy*> m_enemies;
    std::vector<Player*> m_players;
    Eagle* m_eagle;

    std::vector<SDL_Rect*> m_rec;

    unsigned m_current_level;

    bool m_level_start_screen;
    Uint32 m_level_start_time;

    bool m_game_over;
    double m_game_over_position;
    bool m_finished;
};

#endif // GAME_H
