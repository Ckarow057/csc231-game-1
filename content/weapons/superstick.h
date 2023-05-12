#pragma once

#include "actor.h"
#include "weapon.h"

class Superstick : public Weapon {
public:
    Superstick(int damage);
    void use(Engine& engine, Actor& attacker, Actor& defender) override;
};