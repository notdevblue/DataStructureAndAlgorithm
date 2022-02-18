#include <iostream>
#include <queue>
#include "Dijkstra/graph.h"
#include "Node/node.h"

int main()
{
    graph* g = new graph();

    g->add_new_node(new NODE());
    g->add_new_node(new NODE());
    g->add_new_node(new NODE());
    g->add_new_node(new NODE());

    g->set_linked_status(1, 2, 10);
    g->set_linked_status(1, 3, 5);

    g->set_linked_status(2, 4, 2);
    g->set_linked_status(3, 4, 5);

    NODE *node = g->closest_route(1, 4);
    if(node == nullptr) {
        std::cerr << "err" << std::endl;
        return (1);
    }

    std::queue<NODE *>* route_history = g->get_route_history();

    while(!route_history->empty()) {
        NODE *history_node = route_history->front();
        std::cout << "NODE id: " << history_node->id << std::endl;
        route_history->pop();
    }

    delete g;
    g = nullptr;

    return (0);
}