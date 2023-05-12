#pragma once
#include "action.h"
#include "monstertype.h"
namespace Monsters {
std::unique_ptr<Action> default_behavior(Engine& engine, Monster& me);

MonsterType goblin();

MonsterType orc_masked();

MonsterType ogre();

MonsterType demon_big();

MonsterType skeleton();

MonsterType necromancer();

MonsterType zombie();

MonsterType demon_tiny();

MonsterType shaman();

}  // namespace Monsters
