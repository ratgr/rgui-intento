#include <map>

class PropertyBase;

class PropertyEvent
{
private:
    PropertyBase* Parent_Property;
    std::map<long, basefuncT> functions;
    long count = 0; 

public:
    
    PropertyEvent(PropertyBase* parent);

    int add(func<void(PropertyBase)>);
    
    template <class T>
        int add(func<void(Property<T>&)>);
    
    void remove(int);
    
}


#include "PropertyEvent.impl"