#ifndef _BINARY_SEARCH_TREE_
#define _BINARY_SEARCH_TREE_

#include <iostream>
#include <initializer_list>

namespace data_structures {

template <class _Tp>
struct Node{
    Node* _left;
    Node* _right;
    _Tp _data;

    Node() : _left(nullptr), _right(nullptr), _data(_Tp()) {}
    Node(const Node* __left = nullptr, const Node* __right = nullptr, const _Tp& __data = _Tp()) : 
         _left(__left), _right(__right), _data(__data) {}

    virtual ~Node() = default;
};

template <class _Tp>
class BinarySearchTree final {
  public:
    BinarySearchTree() = default;
    

    BinarySearchTree(const BinarySearchTree&) = delete;
    BinarySearchTree(BinarySearchTree&&) = delete;

    void insert(const _Tp& value) {
      // TODO
    }

    void remove(const _Tp& value) {
      // TODO
    }

    

    virtual ~BinarySearchTree() {
      // TODO
    }

  private:
    Node<_Tp>* _root;
};

}; // namespace data_structures

#endif // _BINARY_SEARCH_TREE_