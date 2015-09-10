template<class T>
struct Optional
{
    enum Optionals {NoValue, HasValue }
    
    
    bool hasValue(){return has;}
    T getValue(return val;); 
    
    //Set Values & HasValue
    T operator = (T value);
    
    //Set NoValue, error if set to HasValue
    T operator = (Optionals value);
        
    bool operator == (Optionals value);
    
    bool operator == (T value);
    bool operator >  (T value);
    bool operator <  (T value);
    bool operator >= (T value);
    bool operator <= (T value);
    
    operator T();
    

private:
    bool has;
    T val;
}

struct PropertyBase
{
    
    enum values{inherit, initial, unset}
    
    property set;
    
    std::string Property_name;
    
    RGUI::UIBase* Property_parent;
    
    virtual bool setValue(PropertyBase value) = 0;
    
    template<class T> T* getValue(){return nullptr;}
    
    template<class T> 
        Property<T>* getValue<Property<T>>()
    { 
        if(Property<T>* stm = dynamic_cast<Property<T>*>(this)) return stm;
        return nullptr;
    };
        
    PropertyBase(RGUI::UIBase* parent, std::string name): Property_name(name), Property_parent(parent)
    {
        parent->properties.add(name, this);
    }
     
}

template<class T> 
    struct Property
{
    
    T data;
    
    
}

struct Align : PropertyBase
{
    enum align {auto_, stretch, center, flex_start, flex_end, baseline}
    
    Property<align> content;
    Property<align> items;
    Property<align> self;
    
    Align()
    
}

namespace TimingFunctions
{

    struct TimingFunction
    {
        //returns percentage
        virtual double operator(double percent) = 0 ; 
    }
    
    
    template<double x0,double y0, double x1, double y1>
    struct cubicBezier : TimingFunction
    {
        static cubicBezier<x0,y0,x1,y1> function;
        
        double operator(double x) 
        {
            return  3 * (1 - x)^2 * x^1 * y0 + 3 * (1 - x) * x^2 * y1 + x^3
        }

    };
    
    static struct : TimingFunction 
    {
        double operator(double percent) override
        {
            return percent;
        }
    } linear; 
    
    static cubicBezier<0.25, 0.1, 0.25, 1> ease;
    static cubicBezier<0.42, 0, 1, 1> ease_in;
    static cubicBezier<0, 0, 0.58, 1> ease_out;
    static cubicBezier<0.42, 0, 0.58, 1> ease_in_out;
    
    
}

struct Animation : Property<Animation>
{
    
    enum fillMode {none,forwards,backwards,both};
    enum playState{paused, running}
    
    using seconds = std::chrono::seconds;
    
    Property<std::string> name; 
    Property<seconds> duration;  
    Property<TimingFunction> timing_function;
    Property<seconds> delay;
    Property<int> iteration_count;
    Property<fillMode> fill_mode;
    Property<playState> play_state;
    
    Animation(std::string name, RGUI::UIBase parent): 
        Property<Animation>(parent, name),
        name(parent, name +"-name"),
        duration(parent, name + "-duration"),
        timing_function(name + "-timing-function"),
        delay(name + "-delay", parent),
        iteration_count(name + "-iteration-count"),
        fill_mode(name +"-fill-mode"),
        play_state(name + "-play-state")
    {}
    
}

struct Margin : Property<Margin>
{   
    Property<double> top; 
    Property<double> left;
    Property<double> right;
    Property<double> bottom;
    
    Margin(std::string name, RGUI::UIBase parent): 
        Property<Margin>(name, parent)
        top(name+"-top", parent),
        left(name+"-left", parent),
        right(name+"-right", parent),
        bottom(name+"-bottom", parent),
    {}
    
    Margin( Property<double> top, Property<double> left, Property<double> right, Property<double> bottom)
        top(top), left(left), right(right), bottom(bottom)
    {}
    
    
}

class RGUI::UIBase
{
    Properties properties;
    Styles styles;
    Style initial;
    
    Margin margin;
    Margin padding; 
    Margin border;
    
    UIBase() : margin(this, "margin"), padding(this, "padding"), border(this, "border")
    {};
}


class RGUI::Window : RGUI::UIBase{

    Window()
    {}
    

}

class MainWindow : RGUI::Window
{
public:
    

}
