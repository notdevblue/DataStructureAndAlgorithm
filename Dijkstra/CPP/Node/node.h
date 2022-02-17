#include <vector>

typedef struct _node
{
    // 연결된 노드를 가지고 있는 배열
    std::vector<_linkednode> linked;
    int id;
} NODE;

typedef struct _linkednode
{
    _node connected;
    int cost;
} LINKEDNODE;