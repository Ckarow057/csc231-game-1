# Actions
```C++
class Action {
public:
//override this 
virtual Result perform(Engine& engine) = 0;

protected:
std::shared_ptr<Actor> actor;
};
```
Remeber that Actions contain a shared_ptr<Actor> called actor

##Results
return these from Action::perform()
- success() it worked
- failure() take another turn
- aternative(do_this_instead{})

##MOVING
- Vec; stores (x,y) positions, (0,0) is bottom left
- Actor contains public member functions
- Tiles; Tile& tile = engine.dungeon.tiles(position)
- Tile; Properties = is_wall() , bool walkable , Actor* actor