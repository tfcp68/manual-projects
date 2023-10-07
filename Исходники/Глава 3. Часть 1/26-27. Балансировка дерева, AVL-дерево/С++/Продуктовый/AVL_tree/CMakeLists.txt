cmake_minimum_required(VERSION 3.24)
project(AVL_tree)

set(CMAKE_CXX_STANDARD 17)

add_executable(AVL_tree AVL_tree.h Tests.h Tests.cpp AVL_tree.tpp AVL_tree_private.tpp)
