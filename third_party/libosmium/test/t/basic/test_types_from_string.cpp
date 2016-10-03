#include "catch.hpp"

#include <osmium/osm/types.hpp>
#include <osmium/osm/types_from_string.hpp>

TEST_CASE("set ID from string") {
    REQUIRE(osmium::string_to_object_id("0") == 0);
    REQUIRE(osmium::string_to_object_id("17") == 17);
    REQUIRE(osmium::string_to_object_id("-17") == -17);
    REQUIRE(osmium::string_to_object_id("01") == 1);

    REQUIRE_THROWS_AS(osmium::string_to_object_id(""), std::range_error);
    REQUIRE_THROWS_AS(osmium::string_to_object_id(" "), std::range_error);
    REQUIRE_THROWS_AS(osmium::string_to_object_id(" 22"), std::range_error);
    REQUIRE_THROWS_AS(osmium::string_to_object_id("x"), std::range_error);
    REQUIRE_THROWS_AS(osmium::string_to_object_id("0x1"), std::range_error);
    REQUIRE_THROWS_AS(osmium::string_to_object_id("12a"), std::range_error);
    REQUIRE_THROWS_AS(osmium::string_to_object_id("12345678901234567890"), std::range_error);
}

TEST_CASE("set type and ID from string") {
    auto n17 = osmium::string_to_object_id("n17", osmium::osm_entity_bits::nwr);
    REQUIRE(n17.first == osmium::item_type::node);
    REQUIRE(n17.second == 17);

    auto w42 = osmium::string_to_object_id("w42", osmium::osm_entity_bits::nwr);
    REQUIRE(w42.first == osmium::item_type::way);
    REQUIRE(w42.second == 42);

    auto r_2 = osmium::string_to_object_id("r-2", osmium::osm_entity_bits::nwr);
    REQUIRE(r_2.first == osmium::item_type::relation);
    REQUIRE(r_2.second == -2);

    auto d3 = osmium::string_to_object_id("3", osmium::osm_entity_bits::nwr);
    REQUIRE(d3.first == osmium::item_type::undefined);
    REQUIRE(d3.second == 3);

    auto u3 = osmium::string_to_object_id("3", osmium::osm_entity_bits::nwr, osmium::item_type::undefined);
    REQUIRE(u3.first == osmium::item_type::undefined);
    REQUIRE(u3.second == 3);

    auto n3 = osmium::string_to_object_id("3", osmium::osm_entity_bits::nwr, osmium::item_type::node);
    REQUIRE(n3.first == osmium::item_type::node);
    REQUIRE(n3.second == 3);

    REQUIRE_THROWS_AS(osmium::string_to_object_id("", osmium::osm_entity_bits::nwr), std::range_error);
    REQUIRE_THROWS_AS(osmium::string_to_object_id("n", osmium::osm_entity_bits::nwr), std::range_error);
    REQUIRE_THROWS_AS(osmium::string_to_object_id("x3", osmium::osm_entity_bits::nwr), std::range_error);
    REQUIRE_THROWS_AS(osmium::string_to_object_id("nx3", osmium::osm_entity_bits::nwr), std::range_error);
    REQUIRE_THROWS_AS(osmium::string_to_object_id("n3", osmium::osm_entity_bits::way), std::range_error);
    REQUIRE_THROWS_AS(osmium::string_to_object_id("n3a", osmium::osm_entity_bits::nwr), std::range_error);
}

TEST_CASE("set object version from string") {
    REQUIRE(osmium::string_to_object_version("0") == 0);
    REQUIRE(osmium::string_to_object_version("1") == 1);

    REQUIRE_THROWS_AS(osmium::string_to_object_version("-1"), std::range_error);
    REQUIRE_THROWS_AS(osmium::string_to_object_version(""), std::range_error);
    REQUIRE_THROWS_AS(osmium::string_to_object_version(" "), std::range_error);
    REQUIRE_THROWS_AS(osmium::string_to_object_version(" 22"), std::range_error);
    REQUIRE_THROWS_AS(osmium::string_to_object_version("x"), std::range_error);
}

TEST_CASE("set changeset id from string") {
    REQUIRE(osmium::string_to_changeset_id("0") == 0);
    REQUIRE(osmium::string_to_changeset_id("1") == 1);

    REQUIRE_THROWS_AS(osmium::string_to_changeset_id("-1"), std::range_error);
    REQUIRE_THROWS_AS(osmium::string_to_changeset_id(""), std::range_error);
    REQUIRE_THROWS_AS(osmium::string_to_changeset_id(" "), std::range_error);
    REQUIRE_THROWS_AS(osmium::string_to_changeset_id(" 22"), std::range_error);
    REQUIRE_THROWS_AS(osmium::string_to_changeset_id("x"), std::range_error);
}

TEST_CASE("set user id from string") {
    REQUIRE(osmium::string_to_user_id("0") == 0);
    REQUIRE(osmium::string_to_user_id("1") == 1);
    REQUIRE(osmium::string_to_user_id("-1") == -1);

    REQUIRE_THROWS_AS(osmium::string_to_user_id("-2"), std::range_error);
    REQUIRE_THROWS_AS(osmium::string_to_user_id(""), std::range_error);
    REQUIRE_THROWS_AS(osmium::string_to_user_id(" "), std::range_error);
    REQUIRE_THROWS_AS(osmium::string_to_user_id(" 22"), std::range_error);
    REQUIRE_THROWS_AS(osmium::string_to_user_id("x"), std::range_error);
}

TEST_CASE("set num changes from string") {
    REQUIRE(osmium::string_to_num_changes("0") == 0);
    REQUIRE(osmium::string_to_num_changes("1") == 1);

    REQUIRE_THROWS_AS(osmium::string_to_num_changes("-1"), std::range_error);
    REQUIRE_THROWS_AS(osmium::string_to_num_changes(""), std::range_error);
    REQUIRE_THROWS_AS(osmium::string_to_num_changes(" "), std::range_error);
    REQUIRE_THROWS_AS(osmium::string_to_num_changes(" 22"), std::range_error);
    REQUIRE_THROWS_AS(osmium::string_to_num_changes("x"), std::range_error);
}

