#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <fstream>

enum class Relationship{
    parent,
    child,
    sibling
};

struct Person{
    std::string name;
};

struct RelationshipBrowser{
    //interface
    virtual std::vector<Person> findAllChildren(const std::string& name) = 0;
};

//low-level module provides functionality for data storage
struct Relationships : RelationshipBrowser{
    std::vector<tuple<Person, Relationship, Person>> relationships;

    void addParentChild(const Person& parent, const Person& child){
        relationships.push_back({parent,Relationship::parent,child});
        relationships.push_back({child,Relationship::child,parent});
    }

    std::vector<Person> findAllChildren(const std::string& name) override{
        std::vector<Person> result;
        for(auto&& [first,rel,sec] : relationships){
            if(first.name == name && rel == Relationship::parent){
                result.push_back(sec);
            }
        }
    };
};


//high-level
struct Research{
    //This is bad
    //High-level is dependent on low-level
    /*Research(const Relationships& relationships){
        auto& relations = relationships.relationships;
        for(auto&& [first, rel, sec] : relations)
        {
            if(first.name == "John" && rel == Relationship::parent){
                std::cout << "John is the parent of " << sec.name << std::endl;
            }
        }
    }*/

    //implements interface
    Research(RelationshipBrowser& browser){
        for(auto& child : browser.findAllChildren("John")){
            std::cout << "John has a child called " << child.name << std::endl;
        }
    }
};





int main() {
    Person parent{"John"};
    Person child1{"Chris"}, child2{"Mary"};
    return 0;
}
