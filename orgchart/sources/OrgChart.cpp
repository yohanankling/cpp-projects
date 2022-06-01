#include "OrgChart.hpp"
#include <bits/stdc++.h>
namespace ariel {
//    OrgChart::OrgChart()= default;
//
//    OrgChart::OrgChart(OrgChart &orgChart){
//        this->iterator = orgChart.iterator;
//        this->nodes = orgChart.nodes;
//        this->root = orgChart.root;
//    }
//
//    OrgChart& OrgChart::operator = (const OrgChart &orgChart){
//        this->iterator = orgChart.iterator;
//        this->nodes = orgChart.nodes;
//        this->root = orgChart.root;
//        return *this;
//    }

        Node* OrgChart::getRoot() {
        return &this->root;
    }

    OrgChart &OrgChart::add_root(string const &root) {
        this->root.role = root;
        this->nodes.push_back(&this->root);
        return *this;
    }

    Node* OrgChart::getNode(string const &role){
        for (Node *node: this->nodes) {
            if(node->role == role){
                return node;
            }
        }
        throw invalid_argument("node do not exist");
    }

    OrgChart &OrgChart::add_sub(string const &father, string const &child)
    {
        Node* parent = this->getNode(father);
        Node* kid = new Node();
        kid->role = child;
        parent->childes.push_back(kid);
        this->nodes.push_back(kid);
        return *this;
    }

    void OrgChart::check() {
        if(this->nodes.empty()){
            throw invalid_argument("chart is empty!");
        }
        this->iterator.clear();
    }
    void OrgChart::checkEmpty() {
        if(this->nodes.empty()){
            throw invalid_argument("chart is empty!");
        }
    }

    string* OrgChart::begin()
    {
        return OrgChart::begin_level_order();
    }

    string* OrgChart::end()
    {
        return OrgChart::end_level_order();
    }

    string* OrgChart::begin_level_order()
    {
        this->check();
        vector<Node*> tree;
        tree.push_back(this->getRoot());
        for (uint i = 0; i < tree.size(); ++i) {
            Node *node = tree.at(i);
            iterator.push_back(node->role);
            for(Node *child :node->childes){
                tree.push_back(child);
            }
        }
        return &iterator.at(0);
    }

    string*  OrgChart::end_level_order()
    {
        this->checkEmpty();
        return &this->iterator[this->iterator.size()];
    }

    string*  OrgChart::begin_reverse_order()
    {
        this->check();
        vector<Node*> tree;
        vector<Node*> reverseChildes;
        tree.push_back(this->getRoot());
        for (uint i = 0; i < tree.size(); ++i) {
            Node *node = tree.at(i);
            reverseChildes.clear();
            for(Node *child :node->childes){
                reverseChildes.push_back(child);
            }
            reverse(reverseChildes.begin(), reverseChildes.end());
            tree.insert(tree.end(), reverseChildes.begin(), reverseChildes.end());
            }
        reverse(tree.begin(), tree.end());
        for (Node *node :tree){
            this->iterator.push_back(node->role);
        }
        return &iterator.at(0);
    }

    string*  OrgChart::reverse_order()
    {
        this->checkEmpty();
        return &this->iterator[this->iterator.size()];
    }

    void OrgChart::getDescendant(Node &node){
        iterator.push_back(node.role);
        if(!node.childes.empty()) {
            for (Node *child: node.childes) {
                getDescendant(*child);
            }
        }
    }

    string*  OrgChart::begin_preorder()
    {
        this->check();
        getDescendant(this->root);
        return &iterator.at(0);
    }

    string*  OrgChart::end_preorder()
    {
        this->checkEmpty();
        return &this->iterator[this->iterator.size()];
    }

    string OrgChart::print(Node &father) {
        string level;
        level = father.role + " -> |";
        for (Node *child: father.childes) {
            level += child->role + "|";
        }
        if(father.childes.empty()){
            level += "has no childes|";
        }
        level += "\n";
        this->forPrint.erase(this->forPrint.begin());
        return level;
    }

    void OrgChart::beginForPrint()
    {
        this->check();
        this->forPrint.clear();
        vector<Node*> tree;
        tree.push_back(this->getRoot());
        for (uint i = 0; i < tree.size(); ++i) {
            Node *node = tree.at(i);
            forPrint.push_back(node);
            for(Node *child :node->childes){
                tree.push_back(child);
            }
        }
    }


    ostream &operator<<(ostream &out, OrgChart &tree) {
        tree.check();
        tree.beginForPrint();
        string represent;
        for (Node* node: tree.forPrint) {
            represent += tree.print(*tree.forPrint.at(0));
            // for tidy
            node->role = node->role;
        }
        return out << represent;
    }

//    OrgChart::~OrgChart() {
//        this->iterator.clear();
//        this->nodes.clear();
//        this->forPrint.clear();
//    }

}
