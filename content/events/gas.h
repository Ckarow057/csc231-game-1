#pragma once

#include "animatedsprite.h"
#include "event.h"
#include "vec.h"

class Gas : public Event {
public:
    Gas(Vec position, int damage);
    void execute(Engine& engine) override;
    void when_done(Engine& engine) override;

private:
    Vec position;
    int damage;
    AnimatedSprite sprite;  // execute
};