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

TEST_CASE("insertAVL properly inserts a single node") {
    Node* a = nullptr;
    a = insertAVL(a, 5);

    REQUIRE(a != nullptr);
    REQUIRE(a->data == 5);
    REQUIRE(a->height == 1);
    REQUIRE(treeIsAVL(a));
    releaseAVL(a);
}

TEST_CASE("insertAVL properly inserts a multiple nodes") {
    Node* a = nullptr;
    a = insertAVL(a, 1);
    a = insertAVL(a, 2);
    a = insertAVL(a, 3);

    REQUIRE(a != nullptr);
    REQUIRE(a->left != nullptr);
    REQUIRE(a->right != nullptr);

    REQUIRE(a->data == 2);
    REQUIRE(a->left->data == 1);
    REQUIRE(a->right->data == 3);

    REQUIRE(a->height == 2);
    REQUIRE(a->right->height == 1);
    REQUIRE(a->left->height == 1);

    REQUIRE(treeIsAVL(a));
    releaseAVL(a);
}

TEST_CASE("longer scenario to test if multiple insertAVL and removeAVL result in a proper avl tree") {
    Node* a = nullptr;
    a = insertAVL(a, 1);
    a = insertAVL(a, 2);
    a = insertAVL(a, 3);
    a = insertAVL(a, 4);
    a = insertAVL(a, 5);
    a = insertAVL(a, 6);


    REQUIRE(treeIsAVL(a));
    REQUIRE(a->data == 4);
    REQUIRE(a->left->data == 2);
    REQUIRE(a->left->left->data == 1);
    REQUIRE(a->left->right->data == 3);
    REQUIRE(a->right->data == 5);
    REQUIRE(a->right->right->data == 6);

    REQUIRE(a->height == 3);
    REQUIRE(a->left->height == 2);
    REQUIRE(a->left->left->height == 1);
    REQUIRE(a->left->right->height == 1);
    REQUIRE(a->right->height == 2);
    REQUIRE(a->right->right->height == 1);

    a = removeAVL(a, 2);

    REQUIRE(treeIsAVL(a));
    REQUIRE(a->data == 4);
    REQUIRE(a->left->data == 1);
    REQUIRE(a->left->left == nullptr);
    REQUIRE(a->left->right->data == 3);
    REQUIRE(a->right->data == 5);
    REQUIRE(a->right->right->data == 6);

    REQUIRE(a->height == 3);
    REQUIRE(a->left->height == 2);
    REQUIRE(a->left->right->height == 1);
    REQUIRE(a->right->height == 2);
    REQUIRE(a->right->right->height == 1);

    a = insertAVL(a, 10);

    REQUIRE(treeIsAVL(a));
    REQUIRE(a->data == 4);
    REQUIRE(a->left->data == 1);
    REQUIRE(a->left->right->data == 3);
    REQUIRE(a->right->data == 6);
    REQUIRE(a->right->right->data == 10);
    REQUIRE(a->right->left->data == 5);

    REQUIRE(a->height == 3);
    REQUIRE(a->left->height == 2);
    REQUIRE(a->left->right->height == 1);
    REQUIRE(a->right->height == 2);
    REQUIRE(a->right->right->height == 1);
    REQUIRE(a->right->left->height == 1);

    a = removeAVL(a, 6);

    REQUIRE(treeIsAVL(a));
    REQUIRE(a->data == 4);
    REQUIRE(a->left->data == 1);
    REQUIRE(a->left->right->data == 3);
    REQUIRE(a->right->data == 5);
    REQUIRE(a->right->right->data == 10);
    REQUIRE(a->right->left == nullptr);

    REQUIRE(a->height == 3);
    REQUIRE(a->left->height == 2);
    REQUIRE(a->left->right->height == 1);
    REQUIRE(a->right->height == 2);
    REQUIRE(a->right->right->height == 1);

    releaseAVL(a);
}
