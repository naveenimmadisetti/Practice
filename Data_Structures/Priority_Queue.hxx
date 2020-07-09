// Priority Queue Example
// Find on : https://www.hackerearth.com/practice/data-structures/queues/basics-of-queues/practice-problems/algorithm/disk-tower-b7cc7a50/description/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > Solve (vector<int> arr) {
   // Write your code here
   priority_queue<int> pq;
   vector<int> v;
   vector<vector<int>> res;
   int size = arr.size();
   for (int idx = 0; idx < size ; idx++)
   {
       v.push_back(arr[idx]);
   }

   sort(v.begin(), v.end());
   int index = v.size() - 1;

   for (int idx = 0; idx < size ; idx++)
   {
       vector<int> temp;
       pq.push(arr[idx]);
       while(pq.top() == v[index])
       {
           temp.push_back(v[index]);
           pq.pop();
           index--;
       }
       res.push_back(temp);
   }
   return res;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i_arr = 0; i_arr < N; i_arr++) 
    {
        cin >> arr[i_arr];
    }

    vector<vector<int> > out_ = Solve(arr);
    for (int i_out_ = 0; i_out_ < out_.size(); i_out_++) 
    {
        for (int j_out_ = 0; j_out_ < out_[i_out_].size(); j_out_++) 
        {
            cout << out_[i_out_][j_out_] << " ";
        }
        cout << "\n";
    }
}