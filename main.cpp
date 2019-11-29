typedef struct {
    int x;
    int y;
} location_t;

class GameContext {

public:
    GameContext() {
        m_World = new GameWorld();
    }

    ~GameContext() {
        delete m_World;
    }

    void Tick() { m_World->Tick(); }
    void Snap() { m_World->Snap(); }

private:
    GameWorld *m_World;

};

class GameWorld {
public:
    GameWorld() {
        m_Player = new Player();
    }

    ~GameWorld() {
        delete m_Player;
    }

    void Tick();
    void Snap();
private:
    Unit *m_Player;
};

class Map {
    void Tick();
    void Snap();
};

class MapGenerator() {
    void Tick();
    void Snap();
};

class Unit {
    void Tick();
    void Snap();
};

class Player : public Unit {

}

int main(){

    CGameContext context;

    while(true){
        context.Tick();
        context.Snap();
    }

    return 0;
}