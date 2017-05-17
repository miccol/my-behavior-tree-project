#include <iostream>
#include<behavior_tree.h>
using namespace std;




class MyCondition : public BT::ConditionNode
{
public:
    explicit MyCondition(std::string name);
    BT::ReturnStatus Tick();
};

MyCondition::MyCondition(std::string name) : BT::ConditionNode::ConditionNode(name)
{


}

BT::ReturnStatus MyCondition::Tick()
{
    cout << "Checking!" << endl;
    return BT::SUCCESS;
}


class MyAction : public BT::ActionNode
{
public:
    MyAction(std::string name);
    BT::ReturnStatus Tick();
    void Halt();
};

MyAction::MyAction(std::string name) : ActionNode::ActionNode(name)
{

}






BT::ReturnStatus MyAction::Tick()
{

//    int i = 0;

//    while (true && i++ < 5 && get_status()!=BT::HALTED)
//    {
//        std::chrono::milliseconds(1000);
//        cout << "Running!" << endl;


//    }
    cout << "DONE!" << endl;

    return BT::SUCCESS;
}
void MyAction::Halt()
{

}



int main(int argc, char *argv[])
{

    BT::SequenceNode* seq1 = new BT::SequenceNode("a");
    BT::ConditionTestNode* con1 = new BT::ConditionTestNode("c1");
    BT::ConditionTestNode* con2 = new BT::ConditionTestNode("c2");

    MyCondition* my_con_1 = new MyCondition("My condition");
    MyAction* my_act_1 = new MyAction("My action");

    seq1->AddChild(my_con_1);
    seq1->AddChild(my_act_1);

    Execute(seq1, 100);

    return 0;
}
