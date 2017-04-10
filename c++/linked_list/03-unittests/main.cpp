#include <iostream>
#include <memory>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

struct AudioEffect {
  virtual ~AudioEffect() = default;
  virtual void process(float* buf, size_t num) = 0;

  std::shared_ptr<AudioEffect> next;
};

struct DemoEffect : public AudioEffect {
  void process (float* buf, size_t num);
};

void DemoEffect::process(float* buf, size_t num)
{
  return;
}

bool detect_feedback(std::shared_ptr<AudioEffect> &head)
{
  std::shared_ptr<AudioEffect> slow = head;
  std::shared_ptr<AudioEffect> fast = head;

  while ((fast != nullptr) && (fast->next != nullptr)) {
    slow = slow->next;
    fast = (fast->next)->next;

    if (slow == fast)
      return true;
  }

  return false;
}

TEST_CASE("list is a nullptr") {
  std::shared_ptr<AudioEffect> head = nullptr;
  REQUIRE(detect_feedback(head) == false);
}

TEST_CASE("1 element list, no loop") {
  std::shared_ptr<AudioEffect> head = std::make_shared<DemoEffect>();
  REQUIRE(detect_feedback(head) == false);
}

TEST_CASE("1 element list, self-loop") {
  std::shared_ptr<AudioEffect> head = std::make_shared<DemoEffect>();
  head->next = head;

  REQUIRE(detect_feedback(head) == true);
}

//
