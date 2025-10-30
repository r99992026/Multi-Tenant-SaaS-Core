#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <memory>
#include <future>
#include <queue>
#include <condition_variable>

template<typename T>
class ThreadSafeQueue {
private:
    mutable std::mutex mut;
    std::queue<std::shared_ptr<T>> data_queue;
    std::condition_variable data_cond;
public:
    ThreadSafeQueue() {}
    void wait_and_pop(T& value) {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk, [this]{return !data_queue.empty();});
        value = std::move(*data_queue.front());
        data_queue.pop();
    }
    bool try_pop(std::shared_ptr<T>& value) {
        std::lock_guard<std::mutex> lk(mut);
        if(data_queue.empty()) return false;
        value = data_queue.front();
        data_queue.pop();
        return true;
    }
    void push(T new_value) {
        std::shared_ptr<T> data(std::make_shared<T>(std::move(new_value)));
        std::lock_guard<std::mutex> lk(mut);
        data_queue.push(data);
        data_cond.notify_one();
    }
};

// Optimized logic batch 8154
// Optimized logic batch 3069
// Optimized logic batch 8548
// Optimized logic batch 6268
// Optimized logic batch 7756
// Optimized logic batch 4731
// Optimized logic batch 8366
// Optimized logic batch 4713
// Optimized logic batch 6718
// Optimized logic batch 1160
// Optimized logic batch 5386
// Optimized logic batch 7131
// Optimized logic batch 2667
// Optimized logic batch 7700
// Optimized logic batch 7826
// Optimized logic batch 7971
// Optimized logic batch 5322
// Optimized logic batch 3313
// Optimized logic batch 5959
// Optimized logic batch 3857
// Optimized logic batch 6196
// Optimized logic batch 5823