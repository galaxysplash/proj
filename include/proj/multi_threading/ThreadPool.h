#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <proj/utils/types.h>

#include <cstddef>
#include <cstdlib>
#include <expected>
#include <functional>
#include <optional>
#include <thread>
#include <vector>

class ThreadPool {
 public:
  friend class ThreadPoolFactory;
  constexpr static size_t kMinimumThreadCount{2};

  template <typename LambdaReturn, typename... LambdaArgs>
  [[nodiscard("check for errors")]] std::optional<None> offload_work(
      LambdaArgs &&...args,
      const std::function<LambdaReturn(LambdaArgs...)> &&work) noexcept;

  void *operator new(size_t) = delete;
  void operator delete(void *) = delete;

 protected:
  explicit ThreadPool(const size_t thread_count) noexcept
      : thread_count_(thread_count) {}

 private:
  const size_t thread_count_;
  std::vector<std::thread> pool_{};
};

class ThreadPoolFactory {
 public:
  [[nodiscard(
      "your class")]] virtual std::expected<ThreadPool, std::string_view>
  create(const size_t &thread_count =
             std::thread::hardware_concurrency()) noexcept;
};

#endif