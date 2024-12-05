#include <cstdlib>
#include <functional>
#include <memory>
#include <string>
#include <string_view>
#include <unordered_map>

class Engine
{
public:
    virtual ~Engine() noexcept;
};


class Diesel : public Engine
{
};

class Jet : public Engine
{
};

class JetInitializer
{
    JetInitializer()
    {
        EngineFactory::instance().get("")
    }
};

class Warp : public Engine
{
};

class EngineFactory
{
    std::unordered_map<std::string_view, std::function<std::shared_ptr<Engine()>>> creators_;
    EngineFactory() {}

    EngineFactory(const EngineFactory &) = delete;

public:
    void
    reg(std::string_view sv, std::function<std::shared_ptr<Engine>()> f)
    {
        creators_.insert({sv, f});
    }


    std::shared_ptr<Engine>
    create(std::string_view sv)
    {
        return std::make_shared<Jet>();
        abort();
    }

    static EngineFactory &
    instance()
    {
        static EngineFactory inst;
        return inst;
    }
};


class Vehicle
{
protected:
    std::shared_ptr<Engine> engine_;

public:
    Vehicle(std::shared_ptr<Engine> engine) : engine_(engine) {}
    virtual ~Vehicle() noexcept;
};

class Truck : public Vehicle
{
public:
    using Vehicle::Vehicle;
};

int
main()
{
    std::shared_ptr<Vehicle> v1 = std::make_shared<Truck>(EngineFactory::instance().create("Jet"));
}
