#ifndef TESTS_MST_H
#define TESTS_MST_H

#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>

TestSetAdjacencyList test_set_adjacency_list {
	test_set_adjacency_list.test_1();
	test_set_adjacency_list.test_2();
	test_set_adjacency_list.test_3();
	test_set_adjacency_list.test_4();
	test_set_adjacency_list.test_5();
	test_set_adjacency_list.test_6();
	test_set_adjacency_list.test_7();
	test_set_adjacency_list.test_8();
	test_set_adjacency_list.test_9();
	test_set_adjacency_list.test_10();
}

TestCheckConnect test_check_connect;
test_check_connect.test_1();
test_check_connect.test_2();
test_check_connect.test_3();
test_check_connect.test_4();
test_check_connect.test_5();

TestReturnMinEdge test_return_min_edge;
test_return_min_edge.test_1();
test_return_min_edge.test_2();
test_return_min_edge.test_3();
test_return_min_edge.test_4();
test_return_min_edge.test_5();
test_return_min_edge.test_6();

TestTreePrima test_prima;
test_prima.test_1();
test_prima.test_2();
test_prima.test_3();
test_prima.test_4();
test_prima.test_5();
test_prima.test_6();
test_prima.test_7();
test_prima.test_8();
test_prima.test_9();
test_prima.test_10();

TestTreeKraskal test_tree_kraskal;
test_tree_kraskal.test_1();
test_tree_kraskal.test_2();
test_tree_kraskal.test_3();
test_tree_kraskal.test_4();
test_tree_kraskal.test_5();
test_tree_kraskal.test_6();
test_tree_kraskal.test_7();
test_tree_kraskal.test_8();
test_tree_kraskal.test_9();
test_tree_kraskal.test_10();


TestRandomTest random_test;
random_test.test_tree_prima();
random_test.test_tree_kraskal();


#endif
