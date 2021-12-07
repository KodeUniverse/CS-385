#include <iostream>
#include <sstream>
#include <map>
using namespace std;

// Struct to represent state of water in the jugs.
struct State {
	map<const char*, int> jugs;
    int a, b, c;
    string directions;
    State *parent;

    /*State(int _a, int _b, int _c, string _directions) :
        a{_a}, b{_b}, c{_c}, directions{_directions}, parent{nullptr} { }*/
    State(int _a, int _b, int _c)
    {
    	jugs.insert(pair<const char*, int>("A", _a));
    	jugs.insert(pair<const char*, int>("B", _b));
    	jugs.insert(pair<const char*, int>("C",_c));
    	parent = nullptr;
    }

    // String representation of state in tuple form.
    string to_string() {
        ostringstream oss;
        oss << "(" << jugs.at("A") << ", " << jugs.at("B") << ", " << jugs.at("C") << ")";
        return oss.str();
    }
};

int capacities[3];

/*State* initial_state(int& capacities[])
{
	return State(0, 0, capacities[2])
}*/

State* pour(State* curr, const char* from, const char* to)
{
	int pourvalue = curr->jugs.find(from)->second;
	curr->jugs.find(to)->second += pourvalue;
	return curr;
}


int main(int argc, char **argv) {
	capacities[0] = 3;
	capacities[1] = 5;
	capacities[2] = 8;

	State* state1 = new State(1,2,3);
	cout << state1->to_string() << endl;
	cout <<  pour(state1, "A", "C")->to_string() << endl;
}
