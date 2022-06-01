#include "sources/OrgChart.cpp"

using namespace ariel;
int main(){
    OrgChart organization;
    organization.add_root("1")
            .add_sub("1", "11")
            .add_sub("1", "12")
            .add_sub("1", "13")
            .add_sub("11", "111");
    /*
                       1
                     / | \
                    11 12 13
                   /
                  111
    */
    for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
    {
        cout<<*it << "|";
    }
    cout<<endl;
    //"1","11","12","13","111"
    for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
    {
        cout<<*it << "|";
    }
    //"111","11","12","13","1";
    cout<<endl;
    for (auto it=organization.begin_preorder(); it!=organization.end_preorder(); ++it)
    {
        cout<<*it << "|";
    }
    //"1","11","111","12","13"
    cout<<endl;
    //1,2,3,2,2
    for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
    {
        cout<<it->size() << "|";

    }
cout<<endl;
    cout << "print function:" << endl;
    cout<< organization <<endl;
    cout<< "second ORgchart:" << endl;
    OrgChart organization2;
    vector <string> ans;
    organization2.add_root("1");
    for (auto it = organization2.begin_reverse_order(); it != organization2.reverse_order(); ++it)
    {
        cout<<*it << "|";
    }
    //"1"
    cout<<endl;
    organization2.add_sub("1", "1");
    for (auto it=organization2.begin_preorder(); it!=organization2.end_preorder(); ++it) {
        cout << *it << "|";
    }
    //"1","1"
    cout<<endl;
    for (int i = 0; i < 10; ++i) {
        organization2.add_sub("1", "1");
    }
    for (auto it = organization2.begin_level_order(); it != organization2.end_level_order(); ++it)
    {
        cout << *it << "|";
    }
    //1,1,1,1,1,1,1,1,1,1,1,1
    cout<<endl;
    cout << "print function:" << endl;
    cout<< organization <<endl;
    cout<<"third Orgchart:";
    cout<<endl;
    OrgChart organization1;
    organization1.add_root("1")
            .add_sub("1", "11")
            .add_sub("1", "11")
            .add_sub("1", "11")
            .add_sub("11", "111");
    /*
                       1
                     / | \
                    11 11 11
                   /   |   \
                  ?    ?    ?
    */
    for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
    {
        cout << *it << "|";
    }
//"111","11","11","11","1"};
cout<<endl;
    for (auto it = organization1.begin_level_order(); it != organization1.end_level_order(); ++it)
    {
        cout << *it << "|";
    }
    cout << "print function:" << endl;
    cout<< organization <<endl;
//1,2,2,2,3
}
