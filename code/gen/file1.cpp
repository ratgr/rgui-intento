#include <RGUI/UIElements>

namespace gen{

    template< class T>
    class MainWindow : RGUI::Window{

        void Initialize(){

        }

    }

}




struct base 
{
    std::string name;
    
    base(name): name(name)
    {}
    
    base(base&) = delete; 
    
}

struct second : base
{
    second(std::sting n): base("asd")
    {
    
    }
    
    second(second& other): base("asd")
    {
    
    }
}