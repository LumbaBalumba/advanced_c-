#include <memory>
#include <mutex>

struct Account {
    bool active_;
    double balance_;//doulbe не подходит для хранения денежных стредств из-за погрешности
    std::mutex m_;
};

void
transfer(Account &from, Account &to, double amount)
{
    if (std::addressof(from) == std::addressof(to)) {
        return;
    }

    // std::lock_guard lk1{from.m_};
    // std::lock_guard lk2{to.m_}; -- deadlock

    // std::lock(from.m_, to.m_);
    // std::lock_guard l1(from.m_, std::adopt_lock);
    // std::lock_guard l2(to.m_, std::adopt_lock);
    //


    std::scoped_lock l(from.m_, to.m_);

    if (from.active_ && to.active_ && from.balance_ >= amount) {
        from.balance_ -= amount;
        to.balance_ += amount;
    }
}
