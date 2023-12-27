#include <iostream>
using namespace std;
struct Aggregate1 {
    int x;
        struct Aggregate2 {
        int a;
        int b[3];
    } y;
};

int main() {
    int array1[3] = { 1, 2, 3 };
    int array2[3] { 1, 2, 3 };
    Aggregate1 agg1 = { 1, { 2, { 3, 4, 5} } };
    Aggregate1 agg2 { 1, { 2, { 3, 4, 5} } };
    Aggregate1 agg3 = { 1, 2, 3, 4, 5 };
}