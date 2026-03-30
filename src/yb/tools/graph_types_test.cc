#include <iostream>
#include "yb/common/graph_types.h"

using namespace yb::graph;

void TestGraphNode() {
    std::cout << "=== 测试 GraphNode ===" << std::endl;
    
    GraphNode node;
    node.node_id = "user:123";
    node.labels = {"Person", "Employee"};
    node.properties = "{\"name\":\"Alice\",\"age\":30}";
    node.created_at = 1700000000;
    
    std::string json = node.Serialize();
    std::cout << "序列化结果: " << json << std::endl;
    
    GraphNode node2;
    node2.node_id = "user:123";
    node2.labels = {"Person", "Employee"};
    node2.properties = "{\"name\":\"Alice\",\"age\":30}";
    node2.created_at = 1700000000;
    
    std::cout << "节点相等: " << (node == node2 ? "是" : "否") << std::endl;
}

void TestGraphEdge() {
    std::cout << "\n=== 测试 GraphEdge ===" << std::endl;
    
    GraphEdge edge;
    edge.edge_id = "edge:456";
    edge.from_node = "user:123";
    edge.to_node = "user:456";
    edge.relation_type = "FRIEND";
    edge.properties = "{\"since\":2020}";
    edge.created_at = 1700000000;
    
    std::string json = edge.Serialize();
    std::cout << "序列化结果: " << json << std::endl;
}

int main() {
    TestGraphNode();
    TestGraphEdge();
    return 0;
}