#include "rest.h"

#include <iostream>

#include "actor.h"

Result Rest::perform(Engine&) {
    actor->health += 1;
    return success();
}
