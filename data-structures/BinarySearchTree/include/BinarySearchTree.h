#ifndef _BINARY_SEARCH_TREE_
#define _BINARY_SEARCH_TREE_

#include "Node.h"

template <class _Tp>
class BinarySearchTree final {
  public:
    BinarySearchTree() = default;
    BinarySearchTree(const _Tp&);

    BinarySearchTree(const BinarySearchTree&) = delete;
    BinarySearchTree(BinarySearchTree&&) = delete;

    void insert(const _Tp&);
    void remove(const _Tp&);
    
    Node<_Tp>* search(const _Tp&);
    const Node<_Tp>* search(const _Tp&) const;

    Node<_Tp>* getRoot();
    const Node<_Tp>* getRoot() const;

    virtual ~BinarySearchTree();

  private:
    Node<_Tp>* _root;
};

#endif // _BINARY_SEARCH_TREE_