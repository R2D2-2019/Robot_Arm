#include "vector_3D_c.hpp"
#include <iostream>

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include <iostream>

TEST_CASE("Operator==") {
    r2d2::robot_arm::vector_3D_c<float> c(1.f, 5.f, 6.f);
    r2d2::robot_arm::vector_3D_c<float> c2(1.f, 5.f, 6.f);
    REQUIRE(c == c2);
}

TEST_CASE("Default constructor") {
    r2d2::robot_arm::vector_3D_c<int> c;
    REQUIRE(c == r2d2::robot_arm::vector_3D_c<int>(0, 0, 0));
}

TEST_CASE("Constructor, one value") {
    r2d2::robot_arm::vector_3D_c<int> c(5);
    REQUIRE(c == r2d2::robot_arm::vector_3D_c<int>(5, 5, 5));
}

TEST_CASE("Constructor, three values") {
    r2d2::robot_arm::vector_3D_c<int> c(1, 2, 3);
    REQUIRE(c == r2d2::robot_arm::vector_3D_c<int>(1, 2, 3));
}

TEST_CASE("Operator + with coordinate") {
    r2d2::robot_arm::vector_3D_c<int> c(1, 2, 3);
    r2d2::robot_arm::vector_3D_c<int> result =
        c + r2d2::robot_arm::vector_3D_c<int>(1, 2, 3);
    REQUIRE(result == r2d2::robot_arm::vector_3D_c<int>(2, 4, 6));
}

TEST_CASE("Operator + with int") {
    r2d2::robot_arm::vector_3D_c<int> c(1, 2, 3);
    r2d2::robot_arm::vector_3D_c<int> result = c + 1;
    REQUIRE(result == r2d2::robot_arm::vector_3D_c<int>(2, 3, 4));
}

TEST_CASE("Operator += with coordinate") {
    r2d2::robot_arm::vector_3D_c<int> c(1, 2, 3);
    c += r2d2::robot_arm::vector_3D_c<int>(3, 4, 5);
    REQUIRE(c == r2d2::robot_arm::vector_3D_c<int>(4, 6, 8));
}

TEST_CASE("Operator += with int") {
    r2d2::robot_arm::vector_3D_c<int> c(4, 5, 6);
    c += 3;
    REQUIRE(c == r2d2::robot_arm::vector_3D_c<int>(7, 8, 9));
}

TEST_CASE("Operator++") {
    r2d2::robot_arm::vector_3D_c<int> c(1, 2, 3);
    c++;
    REQUIRE(c == r2d2::robot_arm::vector_3D_c<int>(2, 3, 4));
}

TEST_CASE("Operator- with coordinate") {
    r2d2::robot_arm::vector_3D_c<int> c(1, 2, 3);
    r2d2::robot_arm::vector_3D_c<int> result =
        c - r2d2::robot_arm::vector_3D_c<int>(1, 2, 3);
    REQUIRE(result == r2d2::robot_arm::vector_3D_c<int>(0, 0, 0));
}

TEST_CASE("Operator- with int") {
    r2d2::robot_arm::vector_3D_c<int> c(5, 2, 3);
    r2d2::robot_arm::vector_3D_c<int> result = c - 2;
    REQUIRE(result == r2d2::robot_arm::vector_3D_c<int>(3, 0, 1));
}

TEST_CASE("Operator-= with coordinate") {
    r2d2::robot_arm::vector_3D_c<int> c(5, 4, 3);
    c -= r2d2::robot_arm::vector_3D_c<int>(1, 2, 3);
    REQUIRE(c == r2d2::robot_arm::vector_3D_c<int>(4, 2, 0));
}

TEST_CASE("Operator-= with int") {
    r2d2::robot_arm::vector_3D_c<int> c(5, 4, 3);
    c -= 3;
    REQUIRE(c == r2d2::robot_arm::vector_3D_c<int>(2, 1, 0));
}

TEST_CASE("Operator--") {
    r2d2::robot_arm::vector_3D_c<int> c(5, 4, 3);
    c--;
    REQUIRE(c == r2d2::robot_arm::vector_3D_c<int>(4, 3, 2));
}

TEST_CASE("Operator/ with coordinate") {
    r2d2::robot_arm::vector_3D_c<int> c(5, 4, 3);
    r2d2::robot_arm::vector_3D_c<int> result =
        c / r2d2::robot_arm::vector_3D_c<int>(1, 2, 3);
    REQUIRE(result == r2d2::robot_arm::vector_3D_c<int>(5, 2, 1));
}

TEST_CASE("Operator/ with int") {
    r2d2::robot_arm::vector_3D_c<int> c(4, 10, 20);
    r2d2::robot_arm::vector_3D_c<int> result = c / 2;
    REQUIRE(result == r2d2::robot_arm::vector_3D_c<int>(2, 5, 10));
}

TEST_CASE("Operator/= with coordinate") {
    r2d2::robot_arm::vector_3D_c<int> c(5, 10, 20);
    c /= r2d2::robot_arm::vector_3D_c<int>(5, 2, 2);
    REQUIRE(c == r2d2::robot_arm::vector_3D_c<int>(1, 5, 10));
}

TEST_CASE("Operator/= with int") {
    r2d2::robot_arm::vector_3D_c<int> c(10, 100, 200);
    c /= 2;
    REQUIRE(c == r2d2::robot_arm::vector_3D_c<int>(5, 50, 100));
}
