//Assign Cookies
/*
Problem:
We are given two arrays:
g -> represents the greed factor of each child.
s -> represents the size of each cookie.

Each child i has a greed factor g[i], which is the minimum cookie size 
that can satisfy that child. Each cookie j has a size s[j].

Goal:
Assign cookies to children such that the maximum number of children 
are satisfied. A child is satisfied only if the cookie size is 
greater than or equal to their greed factor.

Approach (Greedy Algorithm):
1. First sort both arrays:
   - Sort g (children greed factors)
   - Sort s (cookie sizes)

2. Use two pointers:
   i -> index for children
   j -> index for cookies

3. Traverse both arrays:
   - If cookie size s[j] >= greed g[i], it means the cookie can satisfy 
     the child. So assign it:
       - increase count of satisfied children
       - move to next child (i++)
       - move to next cookie (j++)
   - Otherwise, the cookie is too small for that child:
       - move to the next cookie (j++)

4. Continue until we run out of children or cookies.

Time Complexity:
O(n log n + m log m) due to sorting.

Space Complexity:
O(1) (no extra space used except variables).

The final value of 'count' represents the maximum number of children
that can be satisfied.
*/
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
     int count = 0, i = 0, j = 0;
        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                count++;
                i++;
                j++;
            } else {
                j++;
            }
        }
    return count;
    }
};