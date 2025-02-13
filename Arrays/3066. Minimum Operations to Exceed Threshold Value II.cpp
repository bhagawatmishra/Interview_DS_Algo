/*
    Resource                    : https://www.youtube.com/watch?v=PVHJh8Gq3js
    Leetcode Link               : https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii
*/

/************************************************************ C++ ************************************************************/
//Approach (Using Heap)
//T.C : Onlogn)
//S.C : O(n)
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long, vector<long>, greater<long>> pq(begin(nums), end(nums)); //Heapify - log(n)

        // Below approach will take TC: nlog(n) so don't use this way
        // for(int &num: nums) {
        //     pq.push(num); // log(n)
        // }

        int count = 0;

        while(!pq.empty() && pq.top() < k) { //O(n)
            long smallest = pq.top(); //minimum
            pq.pop(); //O(logn)

            long secondSmallest = pq.top(); //max
            pq.pop(); //O(logn)

            pq.push(smallest*2 + secondSmallest); //O(logn)

            count++;
        }

        return count;

    }
};