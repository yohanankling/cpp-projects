#pragma once
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;
namespace ariel {

    struct Node{
        string role;
        vector <Node*> childes;
    };

    class OrgChart {
    private:
        Node root;
        vector<Node*> nodes;
        vector<Node*> forPrint;
        vector<string> iterator;
    public:
        OrgChart() = default;
        ~OrgChart() = default;
        OrgChart (OrgChart& orgChart) = default;
        OrgChart (OrgChart&& orgChart) = default;
        OrgChart & operator= (OrgChart && ) = default;
        OrgChart& operator = (const OrgChart& orgChart) = default;
        Node* getRoot();
        void check();
        void checkEmpty();
        Node* getNode(string const &role);
        OrgChart &add_root(string const &root);
        OrgChart &add_sub(string const &father, string const &child);
        string*  begin();
        string*  end();
        string*  begin_level_order();
        string*  end_level_order();
        string*  begin_reverse_order();
        string*  reverse_order();
        void getDescendant(Node &node);
        string*  begin_preorder();
        string*  end_preorder();
        void beginForPrint();
        string  print(Node &father);
        friend ostream &operator<<(ostream &out, OrgChart &tree);
    };

}