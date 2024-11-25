#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class VectorOperations {
private:
    vector<int> vec;

public:
    void input(int n) {
        vec.clear();
        for (int i = 0; i < n; ++i) {
            int element;
            cin >> element;
            vec.push_back(element);
        }
    }

    void generateRandom(int n) {
        vec.clear();
        srand(time(0));
        for (int i = 0; i < n; ++i) {
            vec.push_back(rand() % 100);
        }
    }

    void setSize(int size, int value = 0) {
        vec.resize(size, value);
    }

    void print() const {
        for (const auto& el : vec) {
            cout << el << " ";
        }
        cout << endl;
    }

    vector<int> getVector() const {
        return vec;
    }

    void setVector(const vector<int>& newVec) {
        vec = newVec;
    }

    VectorOperations copy() const {
        VectorOperations newVecOp;
        newVecOp.setVector(vec);
        return newVecOp;
    }
};

int main() {
    VectorOperations v1, v2, v3, v4, v5;

    int n;
    cout << "Enter number of elements for v1: ";
    cin >> n;
    v1.input(n);

    v2.setSize(10);

    cout << "Enter number of elements for v3: ";
    cin >> n;
    v3.generateRandom(n);

    v4 = v1.copy();

    vector<int> tempVec = v3.getVector();
    vector<int> v5Data(tempVec.begin() + 1, tempVec.end() - 1);
    v5.setVector(v5Data);

    cout << "v1: ";
    v1.print();

    cout << "v2: ";
    v2.print();

    cout << "v3: ";
    v3.print();

    cout << "v4: ";
    v4.print();

    cout << "v5: ";
    v5.print();

    return 0;
}
