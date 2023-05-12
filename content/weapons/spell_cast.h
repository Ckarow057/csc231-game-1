#pragma once

#include "actor.h"
#include "weapon.h"

class Spell_cast : public Weapon {
public:
    Spell_cast(int damage);
    void use(Engine& engine, Actor& attacker, Actor& defender) override;
};