#include <iostream>
#include <vector>
using namespace std;

void findSubsets(vector<int>& a, int index, int sum, int target, vector<int>& current) {
    if (sum == target) {
        for (int x : current)
            cout << x << " ";
        cout << endl;
        return;
    }

    if (index == a.size() || sum > target)
        return;

    current.push_back(a[index]);
    findSubsets(a, index + 1, sum + a[index], target, current);

    current.pop_back();
    findSubsets(a, index + 1, sum, target, current);
}

int main() {
    int n, target;

    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cin >> target;

    vector<int> current;

    findSubsets(a, 0, 0, target, current);

    return 0;
}

