#include "graph.h"
#include <iostream>

graph::graph() : m_nodeid(0) {
    m_route_history = new std::queue<NODE *>();
}

graph::~graph() {
    std::vector<NODE *>::iterator iter = m_nodes.begin();

    for (; iter != m_nodes.end(); ++iter) {
        std::vector<LINKEDNODE *>::iterator linked_iter = (*iter)->linked.begin();
        for (; linked_iter != (*iter)->linked.end(); ++linked_iter) {
            delete *linked_iter;
            *linked_iter = nullptr;
        }

        delete *iter;
        *iter = nullptr;
    }

    delete m_route_history;
    m_route_history = nullptr;
}

void graph::add_new_node(NODE* node) {
    node->id = ++m_nodeid;
    m_nodes.push_back(node);
}

void graph::set_linked_status(int target_node_id, int linked_nodes_id, int cost) {
    NODE* node = find(target_node_id);
    NODE* target = find(linked_nodes_id);

    LINKEDNODE *linked = new LINKEDNODE();
    linked->connected = target;
    linked->cost = cost;
    node->linked.push_back(linked);
}

NODE* graph::find(int target_id) {
    // O(n); 불편하네요
    std::vector<NODE *>::iterator iter = m_nodes.begin();

    for (; iter != m_nodes.end(); ++iter) {
        if((*iter)->id == target_id) {
            return *iter;
        }
    }

    throw "NodeNotFoundException";
}

NODE* graph::closest_route(int begin_node_id, int destination_node_id) {
    m_destination_node_id = destination_node_id;
    return route(begin_node_id);
}

NODE* graph::route(int node_a_id) {
    int lowest_cost = 2147483647; // int maxvalue
    NODE* lowest_cost_node = nullptr;

    NODE begin_node = *find(node_a_id);
    
    std::vector<LINKEDNODE *>::iterator iter = begin_node.linked.begin();

    for (; iter != begin_node.linked.end(); ++iter) { // cost 제일 작은 걸로 따라가기는 함 -> 길 없으면 되돌아가는 기능 만들어야 함
        int cost = (*iter)->cost;
        if (lowest_cost >= cost) {
            lowest_cost = cost;
            lowest_cost_node = (*iter)->connected;
        }
    }

    m_route_history->push(lowest_cost_node);

    if(lowest_cost_node->id == m_destination_node_id) {
        return lowest_cost_node;
    } else {
        return route(lowest_cost_node->id);
    }
}

std::queue<NODE *>* graph::get_route_history() {
    return m_route_history;
}