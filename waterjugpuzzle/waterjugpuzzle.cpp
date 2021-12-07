/******************************************************************************
 * Name        : waterjugpuzzle.cpp
 * Authors     : Dakshin Kannaan, Dimitri Niles
 * Date        : 11-15-21
 * Description : Solve the water jug puzzle using breadth-first search in C++
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;
/*using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stoi;
using std::atoi;
using std::vector;
using std::ostringstream;
using std::cerr;
using std::queue;*/

// Struct to represent state of water in the jugs.
struct State
{
    int a, b, c;
    string directions;

    State(int _a, int _b, int _c) :
        a{_a}, b{_b}, c{_c} { }

    State(int _a, int _b, int _c, string _directions) :
        a{_a}, b{_b}, c{_c}, directions{_directions} { }
    // String representation of state in tuple form.
    string to_string()
    {
        ostringstream oss;
        oss << "(" << a << ", " << b << ", " << c << ")";
        return oss.str();
    }

	void add_directions(string x)
	{
		directions += x;
	}

	void print_directions()
	{
		cout << directions << endl;
	}

};
//Initializing global states
State capacity(0,0,0);

void setNullState(State x)
{
	x.a = -1, x.b = -1, x.c = -1;
}

bool can_pour(int x, int y, int y_full)
{
	return (x == 0 || y == y_full) ? false : true;
}

string as_string(int x, int y, int y_full, int case_)
{ //For checking grammar of the string output, gallon VS gallons.
	ostringstream amount;
	if (case_)
	{
		switch(x)
		{
			case 1:
				amount << "Pour " << x << " gallon ";
				break;
			default:
				amount << "Pour " << x << " gallons ";
				break;
		}
	}
	else
	{
		switch((y_full - y))
		{
			case 1:
				amount << "Pour " << (y_full - y) << " gallon ";
				break;
			default:
				amount << "Pour " << (y_full - y) << " gallons ";
				break;
		}
	}
	return amount.str();
}

State pour(State x, int pour_case, State full)
{
	ostringstream directions;
	State y = x;

	switch (pour_case)
	{
	//C to A
		case 1:
			switch(can_pour(x.c, x.a, full.a))
			{
				case true:
					if ((full.a - x.a) >= x.c)
					{
						y.a = x.a + x.c;
						y.c = 0;
						directions << as_string(x.c, x.a, full.a, true) << "from C to A. "
								<< y.to_string() << "\n";
					}
					else
					{
						y.a = full.a;
						y.c = x.c - (full.a - x.a);
						directions << as_string(x.c, x.a, full.a, false) << "from C to A. "
								<< y.to_string() << "\n";
					}
					break;
				case false:
					setNullState(y);
					break;
			}
			break;
		case 2:
		//B to A
			switch(can_pour(x.b, x.a, full.a))
			{
				case true:
					if((full.a - x.a) >= x.b)
					{
						y.a = x.a + x.b;
						y.b = 0;
						directions << as_string(x.b, x.a, full.a, true) << "from B to A. "
								<< y.to_string() << "\n";
					}
					else
					{
						y.a = full.a;
						y.b = x.b - (full.a - x.a);
						directions << as_string(x.b, x.a, full.a, false) << "from B to A. "
								<< y.to_string() << "\n";
					}
					break;
				case false:
					setNullState(y);
					break;
			}
			break;
		case 3:
			//C to B
			switch(can_pour(x.c, x.b, full.b))
			{
				case true:
					if ((full.b - x.b) >= x.c)
					{
						y.b = x.b + x.c;
						y.c = 0;
						directions << as_string(x.c, x.b, full.b, true) << "from C to B. "
								<< y.to_string() << "\n";
					}
					else
					{
						y.b = full.b;
						y.c = x.c - (full.b - x.b);
						directions << as_string(x.c, x.b, full.b, false) << "from C to B. "
								<< y.to_string() << "\n";
					}
					break;
				case false:
					setNullState(y);
					break;
			}
			break;
		case 4:
			//A to B
			switch(can_pour(x.a, x.b, full.b))
			{
				case true:
					if ((full.b - x.b) >= x.a)
					{
						y.b = x.b + x.a;
						y.a = 0;
						directions << as_string(x.a, x.b, full.b, true) << "from A to B. "
								<< y.to_string() << "\n";
					}
					else
					{
						y.b = full.b;
						y.a = x.a - (full.b - x.b);
						directions << as_string(x.a, x.b, full.b, false) << "from A to B. "
								<< y.to_string() << "\n";
					}
					break;
				case false:
					setNullState(y);
					break;
			}
			break;
		case 5:
			//B to C
			switch(can_pour(x.b, x.c, full.c))
			{
				case true:
					if ((full.c - x.c) >= x.b)
					{
						y.c = x.c + x.b;
						y.b = 0;
						directions << as_string(x.b, x.c, full.c, 1) << "from B to C. "
								<< y.to_string() << "\n";
					}
					else
					{
						y.c = full.c;
						y.b = x.b - (full.c - x.c);
						directions << as_string(x.b, x.c, full.c, 2) << "from B to C. "
								<< y.to_string() << "\n";
					}
					break;
				case false:
					setNullState(y);
					break;
			}
			break;
		case 6:
			//A to C
			switch(can_pour(x.a, x.c, full.c))
			{
				case true:
					if ((full.c - x.c) >= x.a)
					{
						y.c = x.c + x.a;
						y.a = 0;
						directions << as_string(x.a, x.c, full.c, 1) << "from A to C. "
					<< y.to_string() << "\n";
					}
					else
					{
						y.c = full.c;
						y.a = x.a - (full.c - x.c);
						directions << as_string(x.a, x.c, full.c, 2) << "from A to C. "
								<< y.to_string() << "\n";
					}
					break;
				case false:
					setNullState(y);
					break;
			}
			break;
	}
	y.add_directions(directions.str());
	return y;
}

bool in_vector(State x, vector<State> v)
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i].a == x.a && v[i].b == x.b && v[i].c == x.c)
		{
			return true;
		}
	}
	return false;
}

void directions_bfs(State init, State goal)
{
	vector<State> visited;
	queue<State> states; //queue for bfs
	states.push(init);
	visited.push_back(init); //mark initial state as visited
	if (init.a == goal.a && init.b == goal.b && init.c == goal.c)
	{
		init.print_directions();
		return;
	}//BREADTH FIRST SEARCH
	while (!states.empty())
	{
		State curr = states.front();
		int pour_case = 1;
		while(pour_case <= 6)
		{

			if (curr.a == goal.a && curr.b == goal.b && curr.c == goal.c)
			{
				curr.print_directions();
				return;
			}
			State curr = pour(states.front(), pour_case, capacity);
			if (curr.a != -1 && curr.b != -1 && curr.c != -1 && !(in_vector(curr, visited)))
			{
				states.push(curr);
				visited.push_back(curr);
			}
			pour_case++;
		}
		states.pop();
	}
	cout << "No solution." << "\n";
}

int main(int argc, char** argv)
{
	bool error = false;
	if(argc != 7)
	{
		error = true;
		cerr << "Usage: ./waterjugpuzzle <cap A> <cap B> <cap C> <goal A> <goal B> <goal C>" << "\n";
	}

	string letters[6] = {"A","B","C","A","B","C"};
	int index = 0;

	for(char **p_argv = argv + 1; *p_argv != nullptr; p_argv++) //p_argv[argc] is a NULL pointer, argv + 1 is the ADDRESS of 1st arg
	{

		if((!isdigit(**p_argv) || atoi(*p_argv) == 0) && p_argv <= argv + 3)
		{
			error = true;
			const char *letter = letters[index].data();
			printf("Error: Invalid capacity '%s' for jug %s.\n", *p_argv, letter);
		}
		else if(!isdigit(**p_argv))
		{
			error = true;
			const char *letter = letters[index].data();
			printf("Error: Invalid goal '%s' for jug %s.\n", *p_argv, letter);
		}
		index++;
	}

	bool cap_overflow_error = false;
	if(error == false)
	{
	for(int i = 0; i < 3; i++)
		{
			char jugname = 'A' + (i % 3);
			if(stoi(argv[i + 1]) < stoi(argv[i + 4]))
			{
				cap_overflow_error = true;
				printf("Error: Goal cannot exceed capacity of jug %c.\n", jugname);
			}
		}
	}
	if(cap_overflow_error == false && error == false)
	{
		if((stoi(argv[4]) + stoi(argv[5]) + stoi(argv[6])) != stoi(argv[3]))
		{
			printf("Error: Total gallons in goal state must be equal to the capacity of jug C.\n");
		}
		else
		{
			capacity = State((atoi(argv[1])), (atoi(argv[2])), (atoi(argv[3])));
			State initial(0, 0, (atoi(argv[3])));
			ostringstream s;
			s << "Initial state. (0, 0, " << argv[3] << ")\n";
			initial.add_directions(s.str());
			State goal((atoi(argv[4])), (atoi(argv[5])), (atoi(argv[6])));
			directions_bfs(initial, goal);
		}

	}

	return 0;
}
