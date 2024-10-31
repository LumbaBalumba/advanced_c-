#include <mutex>
class A
{
public:
    void
    f1()
    {
        std::lock_guard{m_};
    }

    void
    f2()
    {
        std::lock_guard{m_};
    }

    void
    f3()
    {
        std::lock_guard{m_};
    }

private:
    int f_;
    std::recursive_mutex m_;
};
