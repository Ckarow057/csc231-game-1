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
