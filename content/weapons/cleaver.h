#pragma once

#include "actor.h"
#include "weapon.h"

class Cleaver : public Weapon {
public:
    Cleaver(int damage);
    void use(Engine& engine, Actor& attacker, Actor& defender) override;
};