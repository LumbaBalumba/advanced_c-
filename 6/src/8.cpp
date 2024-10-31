#include <memory>
#include <mutex>
#include <vector>

int
main()
{
    std::vector<std::unique_ptr<std::mutex>> vv(16);

    vv.push_back(std::make_unique<std::mutex>());
}
