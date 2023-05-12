#include "monsters.h"

#include "axe.h"
#include "cleaver.h"
#include "engine.h"
#include "fire_breath.h"
#include "knife.h"
#include "monster.h"
#include "move.h"
#include "none.h"
#include "randomness.h"
#include "rest.h"
#include "spell_cast.h"
#include "sword_big.h"
#include "wabbajack.h"
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
constexpr int double_speed{16};
constexpr int half_speed{4};

MonsterType goblin() {
    int health = 3;
    return {"goblin", double_speed, health, std::make_shared<Knife>(1),
            default_behavior};
}

MonsterType orc_masked() {
    int health = 6;
    return {"orc_masked", double_speed, health, std::make_shared<Axe>(2),
            default_behavior};
}

MonsterType ogre() {
    int health = 25;
    return {"ogre", half_speed, health, std::make_shared<Cleaver>(4),
            default_behavior};
}

MonsterType demon_big() {
    int health = 12;
    return {"demon_big", half_speed, health, std::make_shared<Cleaver>(2),
            default_behavior};
}

MonsterType skeleton() {
    int health = 1;
    return {"skeleton", default_speed, health, std::make_shared<Sword_big>(2),
            default_behavior};
}

MonsterType necromancer() {
    int health = 2;
    return {"necromancer", double_speed, health, std::make_shared<Wabbajack>(0),
            default_behavior};
}

MonsterType zombie() {
    int health = 4;
    return {"zombie", half_speed, health, std::make_shared<Knife>(1),
            default_behavior};
}

MonsterType demon_tiny() {
    int health = 3;
    return {"demon_tiny", double_speed, health, std::make_shared<Knife>(1),
            default_behavior};
}

MonsterType shaman() {
    int health = 5;
    return {"orc_shaman", default_speed, health,
            std::make_shared<Spell_cast>(3), default_behavior};
}

MonsterType dragon() {
    int health = 5;
    return {"dragon", default_speed, health, std::make_shared<Fire_breath>(3),
            default_behavior};
}
}  // namespace Monsters