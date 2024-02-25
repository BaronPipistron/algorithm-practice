#include "../include/Node.h"

template <class _Tp>
Node<_Tp>::Node(const _Tp& __data = _Tp(), const Node<_Tp>* __left = nullptr,
                                           const Node<_Tp>* __right = nullptr) :
                _data(__data), _left(__left), _right(__right)  {}