#pragma once

#include <string>
#include <vector>
#include <cstdint>

#include "yb/util/result.h"
#include "yb/util/status.h"

namespace yb {
namespace graph {

struct GraphNode {
    std::string node_id;           // 节点唯一标识
    std::vector<std::string> labels;  // 节点标签
    std::string properties;        // 属性，JSONB 格式
    int64_t created_at;            // 创建时间戳

    GraphNode() : created_at(0) {}

    // 序列化为字符串
    std::string Serialize() const;

    // 反序列化
    static Result<GraphNode> Deserialize(const std::string& data);

    // 转换为 JSON 字符串
    std::string ToJSON() const;

    // 比较运算符
    bool operator==(const GraphNode& other) const;
    bool operator!=(const GraphNode& other) const;
};

// 图边数据结构
struct GraphEdge {
    std::string edge_id;           // 边唯一标识
    std::string from_node;         // 起始节点 ID
    std::string to_node;           // 目标节点 ID
    std::string relation_type;     // 关系类型
    std::string properties;        // 属性，JSONB 格式
    int64_t created_at;            // 创建时间戳

    GraphEdge() : created_at(0) {}

    // 序列化为字符串
    std::string Serialize() const;

    // 反序列化
    static Result<GraphEdge> Deserialize(const std::string& data);

    // 转换为 JSON 字符串
    std::string ToJSON() const;

    // 比较运算符
    bool operator==(const GraphEdge& other) const;
    bool operator!=(const GraphEdge& other) const;
};

// 图查询结果
struct GraphQueryResult {
    std::vector<GraphNode> nodes;
    std::vector<GraphEdge> edges;

    void Clear() {
        nodes.clear();
        edges.clear();
    }

    bool empty() const {
        return nodes.empty() && edges.empty();
    }
};

}  // namespace graph
}  // namespace yb