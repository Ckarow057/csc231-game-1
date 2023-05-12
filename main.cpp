#include "engine.h"
#include "heros.h"
#include "monsters.h"

int main() {
    std::string filename{"settings.txt"};
    Settings settings = read_settings(filename);
    Engine engine{settings};

    for (int i{0}; i < 4; ++i) {
        engine.create_monster(Monsters::goblin());
        engine.create_monster(Monsters::skeleton());
        engine.create_monster(Monsters::zombie());
        engine.create_monster(Monsters::demon_tiny());
    }

    for (int i{0}; i < 2; ++i) {
        engine.create_monster(Monsters::shaman());
        engine.create_monster(Monsters::orc_masked());
    }

    for (int i{0}; i < 1; ++i) {
        engine.create_monster(Monsters::necromancer());
    }
    engine.create_monster(Monsters::ogre());

    engine.create_hero(Heros::nobody);
    engine.run();
}
