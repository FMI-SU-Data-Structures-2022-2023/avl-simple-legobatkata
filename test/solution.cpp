#include "catch2/catch_all.hpp"
#include "solution.h"

using namespace std;

TEST_CASE("treeIsAVL recognises nullptr as a balanced tree") {
    Node* a = nullptr;
    REQUIRE(treeIsAVL(a));
    releaseAVL(a);
}

TEST_CASE("treeIsAVL recognises a single node as a balanced tree") {
    Node* a = new Node(5);
    REQUIRE(treeIsAVL(a));
    releaseAVL(a);
}

TEST_CASE("treeIsAVL recognises a two correctly ordered nodes as a balanced tree (left)") {
    Node* a = new Node(5);
    a->left = new Node(2);
    REQUIRE(treeIsAVL(a));
    releaseAVL(a);
}

TEST_CASE("treeIsAVL recognises a two correctly ordered nodes as a balanced tree (right)") {
    Node* a = new Node(5);
    a->right = new Node(6);
    REQUIRE(treeIsAVL(a));
    releaseAVL(a);
}

TEST_CASE("treeIsAVL recognises when two wrongly ordered nodes aren't a balanced tree (left)") {
    Node* a = new Node(5);
    a->left = new Node(6);
    REQUIRE_FALSE(treeIsAVL(a));
    releaseAVL(a);
}

TEST_CASE("treeIsAVL recognises when two wrongly ordered nodes aren't a balanced tree (right)") {
    Node* a = new Node(5);
    a->right = new Node(2);
    REQUIRE_FALSE(treeIsAVL(a));
    releaseAVL(a);
}

TEST_CASE("treeIsAVL recognises when a tree isn't balanced due to height difference") {
    Node* a = new Node(5);
    a->height = 3;
    a->right = new Node(6);
    a->right->height = 2;
    a->right->right = new Node(8);
    a->right->right->height = 1;

    REQUIRE_FALSE(treeIsAVL(a));
    releaseAVL(a);
}

TEST_CASE("treeIsAVL recognises when a tree isn't balanced due to wrong order of nodes") {
    Node* a = new Node(5);
    a->height = 2;
    a->right = new Node(4);
    a->right->height = 1;
    a->left = new Node(2);
    a->left->height = 1;

    REQUIRE_FALSE(treeIsAVL(a));
    releaseAVL(a);
}
