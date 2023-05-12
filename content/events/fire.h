#pragma once

#include "animatedsprite.h"
#include "event.h"
#include "vec.h"

class Fire : public Event {
public:
    Fire(Vec position, int damage);
    void execute(Engine& engine) override;
    void when_done(Engine& engine) override;

private:
    Vec position;
    int damage;
    AnimatedSprite sprite;  // execute
};