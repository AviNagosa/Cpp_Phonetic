#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;


TEST_CASE("Test replacement of p and b") {
    string text = "xxx happy yyy";
    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "habby") == string("happy"));
    CHECK(find(text, "hapby") == string("happy"));
    CHECK(find(text, "habpy") == string("happy"));
}

TEST_CASE("Test replacement of a and t/p and b") {
    string text = "xxx happy yyy";
    CHECK(find(text, "htppy") == string("happy"));
    CHECK(find(text, "htbby") == string("happy"));
    CHECK(find(text, "htpby") == string("happy"));
    CHECK(find(text, "htbpy") == string("happy"));
}


TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "Happi xxx yyy";
    CHECK(find(text, "happi") == string("Happi"));
    CHECK(find(text, "Happi") == string("Happi"));
    CHECK(find(text, "HAPPI") == string("Happi"));
    CHECK(find(text, "HaPpI") == string("Happi"));
}

TEST_CASE("Test replacement of b and h/lower-case and upper-case") {
    string text = "bash script";
    CHECK(find(text, "hasH") == string("bash"));
    CHECK(find(text, "Basb") == string("bash"));
}

TEST_CASE("lower-case and upper-case") {
    string text = "bash script";
    CHECK(find(text, "BASH") == string("bash"));
    CHECK(find(text, "baSh") == string("bash"));
    CHECK(find(text, "SCRIPT") == string("script"));
    CHECK(find(text, "sCRIPt") == string("script"));
    CHECK(find(text, " SCRIPT") == string("script"));
    CHECK(find(text, "cript") == string("script"));
}

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "xxx yyyy zzzzz";
    CHECK(find(text, "qqq") == string("xxx"));
    CHECK(find(text, "qqx") == string("xxx"));
    CHECK(find(text, "nnnn") == string("yyyy"));
    CHECK(find(text, "yyny") == string("yyyy"));
    CHECK(find(text, "xzzzz") == string("zzzzz"));
    CHECK(find(text, "jZZZZ") == string("zzzzz"));
    CHECK(find(text, "nyny") == string("yyyy"));
    CHECK(find(text, "XXX") == string("xxx"));
    CHECK(find(text, "ZZZZZ") == string("zzzzz"));
    CHECK(find(text, "YYYY") == string("yyyy"));
    CHECK(find(text, "Zjjjj") == string("yyyyy"));
}


