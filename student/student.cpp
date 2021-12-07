/*******************************************************************************
 * Name    : student.cpp
 * Author  : Dakshin Kannaan
 * Version : 1.0
 * Date    : September 17, 2021
 * Description : Lab 3 Student Class
 * Pledge : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

class Student
{
   private:
    string first_, last_;
    float gpa_;
    int id_;

   public:
    Student(string first, string last, float gpa, int id) : first_{first}, last_{last}, gpa_{gpa}, id_{id} {}

    string full_name() const
    {
        return first_ + " " + last_;
    }

    int id() const
    {
        return id_;
    }

    float gpa() const
    {
        return gpa_;
    }

    void print_info() const
    {
        cout << full_name() << ", GPA: " << fixed << setprecision(2) << gpa() << ", ID: " << id() << "\n";
    }


};

vector<Student> find_failing_students(const vector<Student> &students)
{
    vector<Student> fails;
    for (Student i:students)
    {
        if (i.gpa() < 1.0)
        {
            fails.push_back(i);
        }
    }
    return fails;
}

void print_students(const vector<Student> &students)
{
    for (Student i:students)
    {
    	i.print_info();
    }
}

int main()
{
    string first_name, last_name;
    float gpa;
    int id;
    char repeat;
    vector<Student> students;

    do
    {
        cout << "Enter student's first name: ";
        cin >> first_name;
        cout << "Enter student's last name: ";
        cin >> last_name;
        gpa = -1;
        while (gpa < 0 || gpa > 4) {
            cout << "Enter student's GPA (0.0-4.0): ";
            cin >> gpa;
        }
        cout << "Enter student's ID: ";
        cin >> id;
        students.push_back(Student(first_name, last_name, gpa, id));
        cout << "Add another student to database (Y/N)? ";
        cin >> repeat;
    }
    while (repeat == 'Y' || repeat == 'y');

    cout << "\n"
         << "All students:" << "\n";
    print_students(students);
    cout << "\n"
         << "Failing students:";

    vector<Student> fails = find_failing_students(students);

    if (fails.empty())
    {
        cout << " None";
    }
    else
    {
        cout << "\n";
        print_students(fails);
    }

    return 0;
}
