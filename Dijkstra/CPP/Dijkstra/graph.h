#include <node.h>
#include <vector>

class graph
{
    public:
        graph();
        ~graph();

    private:
        int m_nodeid;
        std::vector<NODE> m_nodes;

    public:
        void add_new_node(NODE node);
        void set_linked_status(int target_node_id, int linked_nodes_id, int cost);
        NODE find(int id);
};