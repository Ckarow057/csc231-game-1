#include "spell_cast.h"

#include "engine.h"
#include "event.h"
#include "hit.h"
#include "lightning.h"

Spell_cast::Spell_cast(int damage) : Weapon{"none", damage} {}

void Spell_cast::use(Engine& engine, Actor&, Actor& defender) {
    engine.events.add(Lightning{defender.get_position(), damage});
}
