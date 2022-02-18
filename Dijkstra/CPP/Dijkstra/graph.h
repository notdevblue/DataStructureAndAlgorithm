#pragma once
#include <vector>
#include <queue>
#include "../Node/node.h"

class graph
{
public:
    graph();
    ~graph();

private:
    int m_nodeid;
    int m_destination_node_id;
    std::vector<NODE *> m_nodes;
    std::queue<NODE *>* m_route_history;

    NODE* route(int node_a_id);

public:
    void add_new_node(NODE *node);
    void set_linked_status(int target_node_id, int linked_nodes_id, int cost);
    NODE *find(int target_id);

    NODE* closest_route(int begin_node_id, int destination_node_id);
    std::queue<NODE *>* get_route_history();
};