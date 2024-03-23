#include <iostream>
#include <list>
#include <unordered_set>

using namespace std;

list<int> iter_solve(list<int> maze[], int start, int finish) {
    unordered_set<int> visited;
    list<int> path;

    path.push_back(start);
    int curr = start;
    visited.insert(curr);

    while (path.back() != finish and path.empty() == false) {
        list<int>::iterator iter = maze[curr].begin();
        bool foundOutlet = false;
        while ((iter != maze[curr].end()) && (!foundOutlet)) {
            if (visited.count(*iter) == 0) {
                foundOutlet = true;
            } else {
                iter++;
            }
        }
        if (foundOutlet) {
            path.push_back(*iter);
            visited.insert(*iter);
        } else {
            path.pop_back();
        }

        curr = path.back();
    }
    return path;
}

bool recur_solve(list<int> maze[], int start, int finish, unordered_set<int>& visited, list<int>& path) {
    if (start == finish) {
        path.push_front(start);
        return true;
    }

    visited.insert(start);
    list<int>::iterator it = maze[start].begin();
    while (it != maze[start].end()) {
        if (visited.count(*it) == 0) {
            if (recur_solve(maze, *it, finish, visited, path)) {
                path.push_front(start);
                return true;
            }
        }
        it++;
    }
    return false;
}

list<int> recur_solve(list<int> maze[], int start, int finish) {
    unordered_set<int> visited;
    list<int> path;
    recur_solve(maze, start, finish, visited, path);
    return path;
}

int main() {
    list<int> maze[9];

    maze[0].push_back(1);
    maze[0].push_back(3);

    maze[1].push_back(0);
    maze[1].push_back(2);

    maze[3].push_back(0);
    maze[3].push_back(4);
    maze[3].push_back(6);

    maze[4].push_back(3);
    maze[4].push_back(5);
    maze[4].push_back(7);

    maze[5].push_back(4);

    maze[6].push_back(3);

    maze[7].push_back(4);
    maze[7].push_back(8);

    maze[8].push_back(7);

    //list<int> path = iter_solve(maze, 0 , 8);
    list<int> path = recur_solve(maze, 0 , 8);

    list<int>::iterator it = path.begin();
    while (it != path.end()) {
        cout << *it;
        it++;
    }
}