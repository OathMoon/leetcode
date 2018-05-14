/*
 * @Author: OathMoon 
 * @Date: 2018-05-14 22:34:19 
 * @Last Modified by: OathMoon
 * @Last Modified time: 2018-05-14 22:47:36
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Employee {
public:
    Employee(int empid, int empimportance, vector<int> empsubordinates)
        : id(empid), importance(empimportance), subordinates(empsubordinates) {}

    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};

int getImportanceSum(unordered_map<int, Employee*>& empmap, int id)
{
    int result = empmap[id]->importance;
    for (auto elem : empmap[id]->subordinates)
    {
        result += getImportanceSum(empmap, elem);
    }

    return result;
}

int getImportance(vector<Employee*> employees, int id)
{
    unordered_map<int, Employee*> empmap;
    for (auto elem : employees)
    {
        empmap[elem->id] = elem;
    }
    
    return getImportanceSum(empmap, id);
}

int main()
{
    vector<Employee*> employees
    {
        (new Employee(1, 5, vector<int> {2, 3})),
        (new Employee(2, 3, vector<int> {})),
        (new Employee(3, 3, vector<int> {}))
    };

    cout << getImportance(employees, 1) << endl;

    return 0;
}