#pragma once

#include "actor.h"
#include "weapon.h"

class Wabbajack : public Weapon {
public:
    Wabbajack(int damage);
    void use(Engine& engine, Actor& attacker, Actor& defender) override;
};