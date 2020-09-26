#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> set_t;
set_t t;
int main() {
    t.insert(5);
    t.insert(6);
    t.insert(3);
    t.insert(1);
    // the smallest is (0), bigest is (n-1), kth small is (k-1)
    int num = *t.find_by_order(0);
    printf("%d\n", num); // print 1
    num = *t.find_by_order(t.size()-1);
    printf("%d\n", num); // print 6
    // find the index
    int index = t.order_of_key(6);
    printf("%d\n", index); // print 3
    // cheak if there exist x
    int x = 5;
    int check = t.erase(x);
    if(check == 0) printf("t not contain 5\n");
    else if(check == 1) printf("t conain 5\n");
    //tree policy like set
    t.insert(5); t.insert(5);
    // get the size of t
    printf("%d\n", t.size()); // print 4
}