#include <string>


template<class T> struct Property;

struct PropertyBase
{
public:
    
    enum AltValues{inherit, initial, unset}
    
    std::string Property_name;
    RGUI::UIBase* Property_parent;
    
    virtual bool setValue(PropertyBase value) = 0;
    
    template<class T> T& getValue();
        
    PropertyBase(RGUI::UIBase* parent, std::string name);
    PropertyBase(PropertyBase&) = delete;
    
private:
    template<class T> friend class Property<T>;
    
    PropertyBase();
}

template<class T>
    struct Property : PropertyBase
{    
    Property(RGUI::UIBase* parent, std::string name);
}

#include "PropertyBase.imp"