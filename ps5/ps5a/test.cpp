/*Copyright 2017 Sam Pickell*/
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>
#include <string>
#include <exception>
#include "RingBuffer.hpp"

BOOST_AUTO_TEST_CASE(RBcontructor) {
        // normal constructor
        BOOST_REQUIRE_NO_THROW(RingBuffer(100));

        // this should fail
        BOOST_REQUIRE_THROW(RingBuffer(0), std::exception);
        BOOST_REQUIRE_THROW(RingBuffer(0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(RBenque_dequeue) {
        RingBuffer rb(3);

        rb.enqueue(2);
        rb.enqueue(1);
        rb.enqueue(0);

        BOOST_REQUIRE(rb.dequeue() == 2);
        BOOST_REQUIRE(rb.dequeue() == 1);
        BOOST_REQUIRE(rb.dequeue() == 0);

        BOOST_REQUIRE_THROW(rb.dequeue(), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(RBpeek) {
        RingBuffer rb(3);

        rb.enqueue(42);
        rb.enqueue(100);
        rb.enqueue(9001);

        // Can't enqueue full buffer
        BOOST_REQUIRE_THROW(rb.enqueue(1), std::runtime_error);

        // Check peek
        BOOST_REQUIRE(rb.peek() == 42);

        BOOST_REQUIRE(rb.dequeue() == 42);
        BOOST_REQUIRE(rb.dequeue() == 100);
        BOOST_REQUIRE(rb.dequeue() == 9001);

        BOOST_REQUIRE_THROW(rb.dequeue(), std::runtime_error);
        // Can't peek into an empty buffer
        BOOST_REQUIRE_THROW(rb.peek(), std::runtime_error);
}
