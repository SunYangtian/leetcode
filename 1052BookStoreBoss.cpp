#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    int calScore(vector<int> &customers, vector<int> &grumpy, int X, int start) {
        int score = 0;
        //分三类。第一类：[0,start), 第二类：[start, start+X),第三类 [start+X, length)
        for (int i=0; i < customers.size(); i++) {
            if (i < start && grumpy[i] == 0) {score += customers[i];}
            else if (i >=start && i < start+X)  {score += customers[i];}
            else if (i >= start+X && grumpy[i] == 0) {score += customers[i];}
            // cout << "score " << score << " ";
        }
        cout << endl;
        return score;
    }

    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int X) {
        int start = 0;
        int score;
        int maxScore = 0;
        while (start+X <= grumpy.size()) {
            // Loop: start from 0 to  length-X
            score = calScore(customers, grumpy, X, start);
            if (score > maxScore) {maxScore = score;}
            start += 1;
        }
        return maxScore;
    }
};

int main() {
    vector<int> customers{1,0,1,2,1,1,7,5};
    vector<int> grumpy{0,1,0,1,0,1,0,1};
    int X = 3;
    
    Solution sol;

//   for (vector<int>::iterator it = customers.begin(); it != customers.end(); ++it)
//     cout << ' ' << *it;
//   cout << '\n';

    cout << sol.maxSatisfied(customers, grumpy, X) << endl;
}