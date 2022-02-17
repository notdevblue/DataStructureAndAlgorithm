#include <graph.h>

graph::graph() : m_nodeid(0) {
    
}

void graph::add_new_node(NODE node) {
    node.id = ++m_nodeid;
    m_nodes.push_back(node);
}

void graph::set_linked_status(int target_node_id, int linked_nodes_id, int cost) {
    NODE node = find(target_node_id);
    NODE target = find(linked_nodes_id);

    LINKEDNODE linked;
    linked.connected = target;
    linked.cost = cost;
    node.linked.push_back(linked);
}

NODE graph::find(int id) {
    // O(n); 불편하네요
    for (NODE node : m_nodes) {
        if(node.id == id) {
            return node;
        }
    }

    throw "NodeNotFoundException";
}