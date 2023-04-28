#include "monsters.h"

#include "engine.h"
#include "monster.h"
#include "move.h"
#include "none.h"
#include "randomness.h"
#include "rest.h"
#include "wander.h"

namespace Monsters {
std::unique_ptr<Action> default_behavior(Engine& engine, Monster& me) {
    // if moster can see hero, pursue
    if (me.is_visible() && engine.hero) {
        std::vector<Vec> path = engine.dungeon.calculate_path(
            me.get_position(), engine.hero->get_position());
        if (path.size() > 1) {
            Vec direction = path.at(1) - path.at(0);
            return std::make_unique<Move>(direction);
        }
    }

    // if monster can't see hero

    if (probability(66)) {
        return std::make_unique<Wander>();
    } else {
        return std::make_unique<Rest>();
    }
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