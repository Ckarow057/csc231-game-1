#pragma once
#include "actor.h"
#include "engine.h"
#include "event.h"

class Die : public Event {
public:
    Die(Actor& actor);
    void execute(Engine& engine) override;

private:
    Actor& actor;
};