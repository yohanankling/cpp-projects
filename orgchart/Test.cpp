#include <stdexcept>
#include "doctest.h"
#include "sources/OrgChart.hpp"
using namespace ariel;
using namespace std;

TEST_CASE("good case") {
    // test for some iterators forms
    OrgChart organization;
    organization.add_root("1")
            .add_sub("1", "11")
            .add_sub("1", "12")
            .add_sub("1", "13")
            .add_sub("11", "111");
    /*
                       1
                     / | \
                    11 12 13
                   /
                  111
    */
    vector <string> ans;
    for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
    {
        ans.push_back(*it);
    }
    vector <string> manualans{"1","11","12","13","111"};
    CHECK_EQ(ans == manualans, true);
    ans.clear();
    manualans.clear();
    for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
    {
        ans.push_back(*it);
    }
    manualans = {"111","11","12","13","1"};
    CHECK_EQ(ans == manualans, true);
    ans.clear();
    manualans.clear();
    for (auto it=organization.begin_preorder(); it!=organization.end_preorder(); ++it)
    {
        ans.push_back(*it);
    }
    manualans = {"1","11","111","12","13"};
    CHECK_EQ(ans == manualans, true);
    vector <int> otherAns;
    vector <int> otherManual {1,2,3,2,2};
    for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
    {
        otherAns.push_back(it->size());
    }
    CHECK_EQ(otherAns == otherManual, true);
}
TEST_CASE("bizarre case") {
    // test for some weird cases - "mikre katse"
    OrgChart organization;
    vector <string> ans;
    for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
    {
        ans.push_back(*it);
    }
    vector <string> manualans{"0"};
            CHECK_EQ(ans == manualans, false);
    manualans.clear();
        CHECK_EQ(ans == manualans, true);
    organization.add_root("1");
    manualans.push_back("1");
    for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
    {
        ans.push_back(*it);
    }
            CHECK_EQ(ans == manualans, true);
    ans.clear();
    for (auto it=organization.begin_preorder(); it!=organization.end_preorder(); ++it) {
        ans.push_back(*it);}
                CHECK_EQ(ans == manualans, true);
    vector <int> otherAns;
    vector <int> otherManual {1};
    for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
    {
        otherAns.push_back(it->size());
    }
            CHECK_EQ(otherAns == otherManual, true);
    organization.add_sub("1", "1");
    ans.clear();
    manualans.clear();
    for (auto it=organization.begin_preorder(); it!=organization.end_preorder(); ++it) {
        ans.push_back(*it);}
    manualans = {"1","1"};
            CHECK_EQ(ans == manualans, true);

    for (int i = 0; i < 10; ++i) {
                CHECK_NOTHROW(organization.add_sub("1", "1"));
    }
    otherAns.clear();
    otherManual.clear();
    for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
    {
        otherAns.push_back(it->size());
    }
    otherManual = {1,1,1,1,1,1,1,1,1,1,1,1};
            CHECK_EQ(otherAns == otherManual, true);
    OrgChart organization1;
    organization1.add_root("1")
            .add_sub("1", "11")
            .add_sub("1", "11")
            .add_sub("1", "11")
            .add_sub("11", "111");
    /*
                       1
                     / | \
                    11 11 11
                   /   |   \
                  ?    ?    ?
    */
    for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
    {
        ans.push_back(*it);
    }
    manualans.clear();
    manualans = {"111","11","11","11","1"};
            CHECK_EQ(ans == manualans, true);
    otherAns.clear();
    otherManual.clear();
    for (auto it = organization1.begin_level_order(); it != organization1.end_level_order(); ++it)
    {
        otherAns.push_back(it->size());
    }
    otherManual = {1,2,2,2,3};
            CHECK_EQ(otherAns == otherManual, true);
}
TEST_CASE("bad case") {
    // add chiled without root
    OrgChart organization;
    vector <string> ans;
    CHECK_THROWS(organization.add_sub("1", "11"));
    organization.add_root("1");
    CHECK_THROWS(organization.add_sub("12", "yohanan"));
    CHECK_THROWS(organization.add_sub("12", "11"));
}
TEST_CASE("two roots case") {
    // add two roots to the same org
    OrgChart organization;
    organization.add_root("1")
            .add_sub("1", "11")
            .add_sub("1", "12")
            .add_sub("1", "13")
            .add_sub("11", "111")
            .add_sub("13", "131");
    /*
                   1
                 / | \
                11 12 13
               /        \
              111       131
*/
    vector <string> ans;
    for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
    {
        ans.push_back(*it);
    }
    vector <string> manualans{"1","11","12","13","111","131"};
            CHECK_EQ(ans == manualans, true);
    ans.clear();
    manualans.clear();
    organization.add_root("0");
    for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
    {
        ans.push_back(*it);
    }
    manualans = {"0","1","11","12","13","111","131"};
            CHECK_EQ(ans == manualans, true);
}

TEST_CASE("add like father case") {
    // add a child with father name
    OrgChart organization;
    organization.add_root("1")
            .add_sub("1", "11")
            .add_sub("1", "12")
            .add_sub("1", "13")
            .add_sub("11", "111")
            .add_sub("13", "131");
    /*
                   1
                 / | \
                11 12 13
               /        \
              111       131
*/
    vector <string> ans;
    for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
    {
        ans.push_back(*it);
    }
    vector <string> manualans = {"111","131","11","12","13","1"};
    CHECK_EQ(ans == manualans, true);
    manualans.clear();
    ans.clear();
    organization.add_sub("12","1");
    /*
               1
             / | \
            11 12 13
           /   |    \
          111  1    131
*/
    for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
    {
        ans.push_back(*it);
    }
    manualans = {"1","11","111","12","1","13","131"};
            CHECK_EQ(ans == manualans, true);
    vector <int> otherAns;
    vector <int> otherManual {1,2,2,2,3,1,3};
    for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
    {
        otherAns.push_back(it->size());
    }
            CHECK_EQ(otherAns == otherManual, true);
}

TEST_CASE("good case2") {
    // test for some iterators forms
    OrgChart organization;
    organization.add_root("1")
            .add_sub("1", "11")
            .add_sub("1", "12")
            .add_sub("1", "13");
    /*
                       1
                     / | \
                    11 12 13
    */
    vector <string> ans;
    for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
    {
        ans.push_back(*it);
    }
    vector <string> manualans{"1","11","12","13"};
            CHECK_EQ(ans == manualans, true);
    ans.clear();
    manualans.clear();
    for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
    {
        ans.push_back(*it);
    }
    manualans = {"11","12","13","1"};
            CHECK_EQ(ans == manualans, true);
    ans.clear();
    manualans.clear();
    for (auto it=organization.begin_preorder(); it!=organization.end_preorder(); ++it)
    {
        ans.push_back(*it);
    }
    manualans = {"1","11","12","13"};
            CHECK_EQ(ans == manualans, true);
    vector <int> otherAns;
    vector <int> otherManual {1,2,2,2};
    for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
    {
        otherAns.push_back(it->size());
    }
            CHECK_EQ(otherAns == otherManual, true);
}
TEST_CASE("bizarre case2") {
    // test for some weird cases - "mikre katse2"
    OrgChart organization;
    vector <string> ans;
    vector <string> manualans;
    organization.add_root("1")
            .add_sub("1", "11")
            .add_sub("11", "111")
            .add_sub("111", "1111")
            .add_sub("1111", "11111")
            .add_sub("11111", "111111");
    /*
     1
     |
     11
      |
     111
      |
    1111
      |
    11111
      |
    111111
    */
    for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
    {
        ans.push_back(*it);
    }
    manualans.clear();
    manualans = {"111111","11111","1111","111","11","1"};
            CHECK_EQ(ans == manualans, true);
    vector <int> otherAns;
    vector <int> otherManual;
    for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
    {
        otherAns.push_back(it->size());
    }
    otherManual = {1,2,3,4,5,6};
            CHECK_EQ(otherAns == otherManual, true);
}