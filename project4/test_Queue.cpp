#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "List.hpp"
#include "Queue.hpp"

/* Provided test cases */
TEST_CASE("Queue: Testing Enqueue", "[queue]") {

  Queue<int, List<int>> queue;

  REQUIRE(queue.isEmpty());
  queue.enqueue(12);
  REQUIRE_FALSE(queue.isEmpty());

}

/* Your test cases here */
TEST_CASE("Queue: Testing Dequeue", "[queue]") {

  Queue<int, List<int>> queue;

  queue.enqueue(12);
  queue.enqueue(13);
  queue.dequeue();
  REQUIRE_FALSE(queue.isEmpty());

  queue.dequeue();
  REQUIRE(queue.isEmpty());
}

TEST_CASE("Queue: Testing Peek", "[queue]") {

  Queue<int, List<int>> queue;

  queue.enqueue(12);
  REQUIRE(queue.peekFront() == 12);
  queue.enqueue(13);
  queue.dequeue();
  REQUIRE_FALSE(queue.isEmpty());
  REQUIRE(queue.peekFront() == 13);

  queue.dequeue();
  REQUIRE(queue.isEmpty());
}