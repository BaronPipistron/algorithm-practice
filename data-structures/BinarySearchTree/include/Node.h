#ifndef _NODE_
#define _NODE_

template <class _Tp>
struct Node final {
    _Tp _data;
    Node<_Tp>* _left;
    Node<_Tp>* _right;

    Node() = default;
    Node(const _Tp& = _Tp(), const Node<_Tp>* = nullptr,
                             const Node<_Tp>* = nullptr);
    Node(const Node&) = delete;
    Node(Node&&) = delete;
    
    virtual ~Node() = default;
};

#endif // _NODE_