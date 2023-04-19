#include "open_door.h"

#include "actor.h"
#include "engine.h"
#include "move.h"

Result OpenDoor::perform(Engine& engine) {
    Vec direction = actor->get_direction();
    Vec position = actor->get_position() + direction;
    Tile& tile = engine.dungeon.tiles(position);
    if (tile.is_door()) {
        Door& door = engine.dungeon.doors.at(position);
        tile.walkable = true;
        actor->move_to(position);
        actor->change_direction(direction);
        door.open();
    }
    return success();
}