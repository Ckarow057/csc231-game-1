#include "fire_breath.h"

#include "engine.h"
#include "event.h"
#include "fire.h"
#include "hit.h"

Fire_breath::Fire_breath(int damage) : Weapon{"none", damage} {}

void Fire_breath::use(Engine& engine, Actor& attacker, Actor& defender) {
    engine.events.add(Fire{defender.get_position(), damage});
}
