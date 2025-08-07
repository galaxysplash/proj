#include <proj/multi_threading/ThreadPool.h>

#include <optional>

std::optional<ThreadPool> ThreadPool::create(
    const size_t thread_count) noexcept {
  if (thread_count < kMinimumThreadCount) {
    return std::nullopt;
  }

  pool_.reserve(thread_count % 2 == 0 ? thread_count : thread_count + 1);
  return ThreadPool{thread_count};
}

template <typename LambdaReturn, typename... LambdaArgs>
std::optional<None> ThreadPool::offload_work(
    LambdaArgs &&...args,
    const std::function<LambdaReturn(LambdaArgs...)> &&work) noexcept {
  if (this->pool_.size() > this->thread_count_) {
    return std::nullopt;
  }
}