/*
g++ priority_queue.cpp -std=c++17 -o /tmp/a.out;/tmp/a.out
*/

#include <bits/stdc++.h>
using namespace std;


struct Person {
  string name;
  int age;
} p1, p2, p3;

struct is_older {
  bool operator()(struct Person p1, struct Person p2) {
    	return p1.age > p2.age;
    }
};

bool compare_names(struct Person p1, struct Person p2) {
    	return p1.name < p2.name;
}



int main(){

    cout << endl << "-----------------------------Heap" << endl; 

    //  max heap
    // priority_queue <int> pq;

    // min heap
    priority_queue <int, vector<int>, greater<int> > pq;

    pq.push(5);
    pq.push(1);
    pq.push(10);
    pq.push(30);
    pq.push(20);

    // Extracting items from the heap
    while (!pq.empty())
    {
        cout << pq.top() << " "; // 1 5 10 20 30
        pq.pop();
    }


    cout << endl << "-----------------------------Custom Object Heap" << endl; 

    // creating heap from user defined objects
    // Let's initialize the properties of `Person` object first
    p1.name = "p1name";
    p1.age = 47;

    p2.name = "p2name";
    p2.age = 46;

    p3.name = "p3name";
    p3.age = 19;

    // Initialize a min heap
    
    // Note: We defined a comparator is_older in the beginning to
    // compare the ages of two people.
    
    priority_queue <struct Person, vector<struct Person>, is_older> mh;
    mh.push(p1);
    mh.push(p2);
    mh.push(p3);

    // Extracting items from the heap
    while (!mh.empty())
    {
    	struct Person p = mh.top();
        cout << p.name << " " << "  age: "<< p.age << endl;
        mh.pop();
    }
    /*
        p3name   age: 19
        p2name   age: 46
        p1name   age: 47    
    */


    cout << endl << "-----------------------------Heap with Vector" << endl; 

    vector<int> h {1,6,4,2,9,7,8};
    cout << "make min heap ";
    make_heap(begin(h), end(h), greater<int>{});
    for (int x : h) { cout << x << ' '; }  // 1 2 4 9 6 7 8
    cout << '\n';

    cout << "make max heap (default) ";
    make_heap(begin(h), end(h));
    for (int x : h) { cout << x << ' '; }  // 9 6 8 2 1 7 4
    cout << '\n';


    cout << endl << "-----------------------------Heap with Vector Manipulations" << endl; 

    vector<int> hp {1,6,4,2,9,7,8};
    make_heap(begin(hp), end(hp), greater<int>{});
    for (int x : hp) { cout << x << ' '; }  // 1 2 4 9 6 7 8
    cout << '\n';

    pop_heap(begin(hp), end(hp), greater<int>{});
    auto oldmin = hp.back();  // oldmin = 1
    cout << "removed: "<< oldmin << "\n";
    hp.pop_back();

    for (int x : hp) { cout << x << ' '; }  // 2 6 4 8 9 7
    cout << '\n';

    pop_heap(begin(hp), end(hp), greater<int>{});
    auto oldmin1 = hp.back();  // oldmin = 2
    cout << "removed: "<< oldmin1 << "\n";
    hp.pop_back();

    for (int x : hp) { cout << x << ' '; }  // 6 4 8 9 7
    cout << '\n';

    cout << "add new element to heap:  333" << "\n";
    hp.push_back(333);
    push_heap(begin(hp), end(hp), greater<int>{});
    for (int x : hp) { cout << x << ' '; }  // 6 4 8 9 7
    cout << '\n';


    return 0;
}
