#include "../include/BinarySearchTree.h"

template <class _Tp>
BinarySearchTree<_Tp>::BinarySearchTree(const _Tp& __root_data) :
                       _root(new Node<_Tp>(__root_data)) {}