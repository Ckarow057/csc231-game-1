#include "monsters.h"

#include "none.h"
#include "rest.h"

namespace Monsters {
std::unique_ptr<Action> default_behavior(Engine& engine, Monster& me) {
    return std::make_unique<Rest>();
}

constexpr int default_speed{8};

MonsterType goblin() {
    int health = 2;
    return {"goblin", default_speed, health, std::make_shared<None>(),
            default_behavior};
}

MonsterType orc_masked() {
    int health = 3;
    return {"orc_masked", default_speed, health, std::make_shared<None>(),
            default_behavior};
}

MonsterType ogre() {
    int health = 4;
    return {"ogre", default_speed, health, std::make_shared<None>(),
            default_behavior};
}

MonsterType demon_big() {
    int health = 4;
    return {"demon_big", default_speed, health, std::make_shared<None>(),
            default_behavior};
}

}  // namespace Monsters