#include "move.h"

#include <iostream>

#include "actor.h"
#include "engine.h"

Move::Move(Vec direction) : direction{direction} {}

Result Move::perform(Engine& engine) {
    Vec position = actor->get_position() + direction;
    // bool is_even = (position.x + position.y) % 2 == 0;
    // for (auto& [p, door] : engine.dungeon.doors) {
    //     // for each position in door
    //     if (is_even) {
    //         door.open();

    //     } else {
    //         door.close();
    //     }
    // }
    actor->get_direction();
    Tile& tile = engine.dungeon.tiles(position);
    if (tile.is_wall()) {
        return failure();
    }
    if (tile.is_door()) {
        return failure();
    }

    // Potential way to block walking over other actors (Can't test yet)
    //  if (tile.walkable == false) {
    //      return failure();
    //  }

    actor->move_to(position);
    actor->change_direction(direction);
    return success();
}
