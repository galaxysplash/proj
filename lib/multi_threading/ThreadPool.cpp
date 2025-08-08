#include <proj/multi_threading/ThreadPool.h>

#include <exception>
#include <expected>
#include <format>
#include <optional>
#include <string_view>
#include <utility>

std::expected<ThreadPool, std::string_view> ThreadPool::create(
    const size_t &thread_count) noexcept {
  if (thread_count < kMinimumThreadCount) {
    return std::unexpected{
        std::format("ThreadPool: thread count has to be bigger than {}",
                    kMinimumThreadCount)};
  }
  auto inst = ThreadPool{thread_count};

  try {
    inst.pool_.reserve(thread_count % 2 == 0 ? thread_count : thread_count + 1);
  } catch (const std::exception &e) {
    return std::unexpected{std::format("ThreadPool: {}", e.what())};
  }

  return std::move(inst);
}

template <typename LambdaReturn, typename... LambdaArgs>
std::optional<None> ThreadPool::offload_work(
    LambdaArgs &&...args,
    const std::function<LambdaReturn(LambdaArgs...)> &&work) noexcept {
  if (this->pool_.size() > this->thread_count_) {
    return std::nullopt;
  }
}