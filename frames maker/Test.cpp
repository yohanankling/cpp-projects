/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 *
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <yohanan>
 *
 * Date: 2021-02
 */

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
    std::erase(input, ' ');
    std::erase(input, '\t');
    std::erase(input, '\n');
    std::erase(input, '\r');
    return input;
}


TEST_CASE("Good input") {
            CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
                                                            "@-------@\n"
                                                            "@-@@@@@-@\n"
                                                            "@-@---@-@\n"
                                                            "@-@@@@@-@\n"
                                                            "@-------@\n"
                                                            "@@@@@@@@@"));
    /* Add more test here */
            // one line
            CHECK(nospaces(mat(5, 1, '@', '-')) == nospaces("@@@@@"));
            // spaces sign
            CHECK(nospaces(mat(3, 1, ' ', ' ')) == nospaces("   "));
            CHECK(nospaces(mat(3, 1, ' ', '#')) == nospaces("   "));
            CHECK(nospaces(mat(1, 3, '!', ' ')) == nospaces(" \n \n \n"));
            // one long line, opposite sign
            CHECK(nospaces(mat(13, 1, '-', '@')) == nospaces("-------------"));
            // one column 3 lines
            CHECK(nospaces(mat(1, 3, '@', '-')) == nospaces("@\n@\n@"));
            // regular
            CHECK(nospaces(mat(13, 5, '@', '-')) == nospaces("@@@@@@@@@@@@@\n@-----------@\n@-@@@@@@@@@-@\n@-----------@\n@@@@@@@@@@@@@"));
            // regular
            CHECK(nospaces(mat(3, 5, '$', '+')) == nospaces("$$$\n$+$\n$+$\n$+$\n$$$"));
}

TEST_CASE("Bad input") {
    CHECK_THROWS(mat(10, 5, '$', '%'));
    /* Add more test here */
    // 2 input even
    CHECK_THROWS(mat(2, 2, '$', '%'));
    // one odd one even
    CHECK_THROWS(mat(3, 2, '$', '-'));
    CHECK_THROWS(mat(9, 8, '+', '-'));

}

/* Add more test cases here */

TEST_CASE("0 input") {
    // negative zero and good number
    CHECK(nospaces(mat(-0, 5, '@', '-')) == nospaces(""));
    // good number and zero
    CHECK(nospaces(mat(5, 0, '@', '-')) == nospaces(""));
    CHECK(nospaces(mat(0, 5, '@', '-')) == nospaces(""));
    // two zero
    CHECK(nospaces(mat(0, 0, '@', '-')) == nospaces(""));
    CHECK(nospaces(mat(-0, -0, '@', '-')) == nospaces(""));

}

TEST_CASE("square input - good") {
    CHECK(nospaces(mat(1, 1, '@', '-')) == nospaces("@"));
    // square with two sign
    CHECK(nospaces(mat(3, 3, '@', '-')) == nospaces("@@@\n@-@\n@@@"));
    // square with one sign
    CHECK(nospaces(mat(3, 3, '$', '$')) == nospaces("$$$\n$$$\n$$$"));
}
TEST_CASE("negative input - bad ") {
            // negative, one odd one even
            CHECK_THROWS(mat(2, -1, '$', '%'));
            CHECK_THROWS(mat(-2, 1, '$', '%'));
            // one negative and good number
            CHECK_THROWS(mat(-3, 1, '$', '%'));
            // negative and zero
            CHECK_THROWS(mat(-5, 0, '$', '%'));
            // two negative even
            CHECK_THROWS(mat(-2, -1, '$', '%'));
            // two negative odd
            CHECK_THROWS(mat(-1, -1, '$', '%'));
}

