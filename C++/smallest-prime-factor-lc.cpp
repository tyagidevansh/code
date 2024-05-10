// class Solution {
// public:
//     vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
//         vector<float> fractions;
//         unordered_map<float, pair<int, int>> hashmap;

//         for (int i = 0; i < arr.size(); i++) {
//             for (int j = i + 1; j < arr.size(); j++) {
//                 float fraction = static_cast<float>(arr[i]) / arr[j];
//                 fractions.push_back(fraction);
//                 hashmap[fraction] = make_pair(arr[i], arr[j]);
//             }
//         }
        
//         sort(fractions.begin(), fractions.end());

//         vector<int> res = {hashmap[fractions[k - 1]].first, hashmap[fractions[k - 1]].second};
//         return res;
//     }
// };

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<>> minHeap;
        int N = arr.size();
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                minHeap.push({(double)arr[i]/arr[j], {arr[i], arr[j]}});
            }
        }

        pair<int, int> res;
        for (int i = 0; i < k; ++i) {
            res = minHeap.top().second;
            minHeap.pop();
        }
        return {res.first, res.second};
    }
};
