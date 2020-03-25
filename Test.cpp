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

TEST_CASE("Test replacement of y and i / y and Y") {
    string text = "xxx happy yyy";
    CHECK(find(text, "iii") == string("yyy"));
    CHECK(find(text, "iyy") == string("yyy"));
    CHECK(find(text, "yyi") == string("yyy"));
    CHECK(find(text, "yiY") == string("yyy"));
    CHECK(find(text, "yyy") == string("yyy"));
    CHECK(find(text, "xxx") == string("xxx"));
    CHECK(find(text, "YYi") == string("yyy"));
    CHECK(find(text, "iYY") == string("yyy"));
}


TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "Happi xxx yyy";
    CHECK(find(text, "happi") == string("Happi"));
    CHECK(find(text, "Happi") == string("Happi"));
    CHECK(find(text, "HAPPI") == string("Happi"));
    CHECK(find(text, "HaPpI") == string("Happi"));
    CHECK(find(text, "hAppi") == string("Happi"));
    CHECK(find(text, "hAbbi") == string("Happi"));
    CHECK(find(text, "hAbpi") == string("Happi"));
    CHECK(find(text, "hApbi") == string("Happi"));
    CHECK(find(text, "hABpi") == string("Happi"));
    CHECK(find(text, "hApBi") == string("Happi"));
    CHECK(find(text, "hABBi") == string("Happi"));
    CHECK(find(text, "hAfpi") == string("Happi"));
    CHECK(find(text, "hApfi") == string("Happi"));
    CHECK(find(text, "hAFpi") == string("Happi"));
    CHECK(find(text, "hApFi") == string("Happi"));
    CHECK(find(text, "hAFFi") == string("Happi"));
    CHECK(find(text, "hafpi") == string("Happi"));
    CHECK(find(text, "hapfi") == string("Happi"));
    CHECK(find(text, "haffi") == string("Happi"));
    CHECK(find(text, "haFFi") == string("Happi"));
    CHECK(find(text, "haFpi") == string("Happi"));
    CHECK(find(text, "hapFi") == string("Happi"));
    CHECK(find(text, "hAppI") == string("Happi"));
    CHECK(find(text, "hAbbI") == string("Happi"));
    CHECK(find(text, "hAbpI") == string("Happi"));
    CHECK(find(text, "hApbI") == string("Happi"));
    CHECK(find(text, "hABpI") == string("Happi"));
    CHECK(find(text, "hApBI") == string("Happi"));
    CHECK(find(text, "hABBI") == string("Happi"));
    CHECK(find(text, "hAfpI") == string("Happi"));
    CHECK(find(text, "hApfI") == string("Happi"));
    CHECK(find(text, "hAFpI") == string("Happi"));
    CHECK(find(text, "hApFI") == string("Happi"));
    CHECK(find(text, "hAFFI") == string("Happi"));
    CHECK(find(text, "hafpI") == string("Happi"));
    CHECK(find(text, "hapfI") == string("Happi"));
    CHECK(find(text, "haffI") == string("Happi"));
    CHECK(find(text, "haFFI") == string("Happi"));
    CHECK(find(text, "haFpI") == string("Happi"));
    CHECK(find(text, "hapFI") == string("Happi"));
}

TEST_CASE("Test for the word bash...") {
    string text = "bash script";
    CHECK(find(text,"fAsh") == string("bash"));
    CHECK(find(text,"fAzh") == string("bash"));
    CHECK(find(text,"fASh") == string("bash"));
    CHECK(find(text,"fASH") == string("bash"));
    CHECK(find(text,"fAsH") == string("bash"));
    CHECK(find(text,"BASH") == string("bash"));
    CHECK(find(text,"BaZh") == string("bash"));
    CHECK(find(text,"baZh") == string("bash"));
    CHECK(find(text,"baSh") == string("bash"));
    CHECK(find(text,"bAsh") == string("bash"));
    CHECK(find(text,"bAsH") == string("bash"));
    CHECK(find(text,"bAzH") == string("bash"));
}

TEST_CASE("Test for the word script...") {
    string text = "bash script";
    CHECK(find(text, "SCRIPT") == string("script"));
    CHECK(find(text, "zcript") == string("script"));
    CHECK(find(text, "zCRIPT") == string("script"));
    CHECK(find(text, "zCRIPt") == string("script"));
    CHECK(find(text, "zCRIpt") == string("script"));
    CHECK(find(text, "zCRipt") == string("script"));
    CHECK(find(text, "zCript") == string("script"));
    CHECK(find(text, "Zcript") == string("script"));
    CHECK(find(text, "ZCRIPT") == string("script"));
    CHECK(find(text, "Zkript") == string("script"));
    CHECK(find(text, "ZkRIPT") == string("script"));
    CHECK(find(text, "ZkriPt") == string("script"));
    CHECK(find(text, "ZkripT") == string("script"));
    CHECK(find(text, "ZkRipt") == string("script"));
    CHECK(find(text, "ZkRIpt") == string("script"));
    CHECK(find(text, "ZkRiPT") == string("script"));
    CHECK(find(text, "ZkRiPt") == string("script"));
    CHECK(find(text, "ZkRipT") == string("script"));
    CHECK(find(text, "SCRYPT") == string("script"));
    CHECK(find(text, "zcrypt") == string("script"));
    CHECK(find(text, "zCRYPT") == string("script"));
    CHECK(find(text, "zCRYPt") == string("script"));
    CHECK(find(text, "zCRYpt") == string("script"));
    CHECK(find(text, "zCRypt") == string("script"));
    CHECK(find(text, "zCrypt") == string("script"));
    CHECK(find(text, "Zcrypt") == string("script"));
    CHECK(find(text, "ZCRYPT") == string("script"));
    CHECK(find(text, "Zkrypt") == string("script"));
    CHECK(find(text, "ZkRYPT") == string("script"));
    CHECK(find(text, "ZkryPt") == string("script"));
    CHECK(find(text, "ZkrypT") == string("script"));
    CHECK(find(text, "ZkRypt") == string("script"));
    CHECK(find(text, "ZkRYpt") == string("script"));
    CHECK(find(text, "ZkRyPT") == string("script"));
    CHECK(find(text, "ZkRyPt") == string("script"));
    CHECK(find(text, "ZkRypT") == string("script"));
}


