#pragma once
#include <vector>

class _node;
class _linkednode;

typedef class _node
{
public:
    // 연결된 노드를 가지고 있는 배열
    std::vector<_linkednode *> linked;
    int id;
} NODE;

typedef class _linkednode
{
public:
    _node *connected;
    int cost;
} LINKEDNODE;