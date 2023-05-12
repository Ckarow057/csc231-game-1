#pragma once

#include "actor.h"
#include "weapon.h"

class Fire_breath : public Weapon {
public:
    Fire_breath(int damage);
    void use(Engine& engine, Actor& attacker, Actor& defender) override;
};