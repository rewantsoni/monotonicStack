#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void findNextLargest(vector<int> arr, vector<int> &res, int n) {
    stack<int> s;

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= arr[i]) s.pop();

        res[i] = (s.empty()) ? -1 : s.top();
        s.push(arr[i]);
    }
}

void findPreviousLargest(vector<int> arr, vector<int> &res, int n) {
    stack<int> s;

    for (int i = 0; i < n; i++) {
        while (!s.empty() && s.top() <= arr[i]) s.pop();

        res[i] = s.empty() ? -1 : s.top();
        s.push(arr[i]);
    }
}

void findNextSmallest(vector<int> arr, vector<int> &res, int n) {
    stack<int> s;

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && s.top() >= arr[i]) s.pop();

        res[i] = s.empty() ? -1 : s.top();
        s.push(arr[i]);
    }
}

void findPreviousSmallest(vector<int> arr, vector<int> &res, int n) {
    stack<int> s;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && s.top() >= arr[i]) s.pop();

        res[i] = s.empty() ? -1 : s.top();
        s.push(arr[i]);
    }
}

void print(const vector<int> &res, const vector<int> &arr, const string &s) {
    cout << s << endl;
    for (int i:arr)
        cout << i << "  ";
    cout << endl;
    for (int i:res)
        cout << i << " ";
    cout << "\n\n";
}


//5 5 --> -1 -1
int main() {
    vector<int> arr = {2, 4, 51, 3, 1, 99, 2, 55, 2, 5, 6, 88, 5};
    int n = arr.size();
    vector<int> res(n, -1);

    //Next Largest
    findNextLargest(arr, res, n);
    print(res, arr, "Next Largest of each element in the array:");

    //Previous Largest
    fill(res.begin(), res.end(), -1);
    findPreviousLargest(arr, res, n);
    print(res, arr, "Previous Largest of each element in the array:");


    //Next Smallest
    fill(res.begin(), res.end(), -1);
    findNextSmallest(arr, res, n);
    print(res, arr, "Next Smallest of each element in the array:");

    //Previous Smallest
    fill(res.begin(), res.end(), -1);
    findPreviousSmallest(arr, res, n);
    print(res, arr, "Previous Smallest of each element in the array:");
    return 0;
}
