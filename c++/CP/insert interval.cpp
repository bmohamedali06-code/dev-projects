#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0, n = intervals.size();
        while(i < n && intervals[i][0] < newInterval[0]){
            i++;
        }
        i--;
        intervals[i][0] = min(intervals[i][0], newInterval[0]);
        intervals[i][1] = max(intervals[i][1], newInterval[1]);
        while(i < intervals.size() - 1){
            if(intervals[i][1] >= intervals[i + 1][0]){
                intervals[i][1] = max(intervals[i][1], intervals[i + 1][1]);
                intervals.erase(intervals.begin() + i + 1);
                i--;
            }
            i++;
        }
        return intervals;
    }
};
void printIntervals(const vector<vector<int>>& intervals) {
    cout << "[";
    for (size_t i = 0; i < intervals.size(); ++i) {
        cout << "[" << intervals[i][0] << "," << intervals[i][1] << "]";
        if (i < intervals.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    Solution solver;

    // Test Case 1: Standard middle insertion with overlap
    vector<vector<int>> intervals1 = {{1, 3}, {6, 9}};
    vector<int> newInterval1 = {2, 5};
    cout << "Test 1 Expected: [[1,5], [6,9]]" << endl;
    cout << "Test 1 Output:   ";
    auto res1 = solver.insert(intervals1, newInterval1);
    printIntervals(res1);
    cout << endl;

    // Test Case 2: Multi-interval merge spanning across several elements
    vector<vector<int>> intervals2 = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<int> newInterval2 = {4, 8};
    cout << "Test 2 Expected: [[1,2], [3,10], [12,16]]" << endl;
    cout << "Test 2 Output:   ";
    auto res2 = solver.insert(intervals2, newInterval2);
    printIntervals(res2);
    cout << endl;

    // Test Case 3: Insertion at the very beginning (no overlap)
    vector<vector<int>> intervals3 = {{3, 5}, {6, 9}};
    vector<int> newInterval3 = {1, 2};
    cout << "Test 3 Expected: [[1,2], [3,5], [6,9]]" << endl;
    cout << "Test 3 Output:   ";
    auto res3 = solver.insert(intervals3, newInterval3);
    printIntervals(res3);
    cout << endl;

    // Test Case 4: Complete containment inside a large interval
    vector<vector<int>> intervals4 = {{1, 10}};
    vector<int> newInterval4 = {2, 5};
    cout << "Test 4 Expected: [[1,10]]" << endl;
    cout << "Test 4 Output:   ";
    auto res4 = solver.insert(intervals4, newInterval4);
    printIntervals(res4);

    return 0;
}