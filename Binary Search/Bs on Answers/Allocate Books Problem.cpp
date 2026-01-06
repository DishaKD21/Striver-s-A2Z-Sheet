//Allocate Books Problem:
/*
 Goal:
 Allocate books to 'm' students such that the maximum number
 of pages assigned to any student is minimized.

 Observation:
 If we increase the allowed maximum pages per student,
 the number of students required will decrease or remain the same.
 This monotonic behavior allows us to apply Binary Search.

 Search Space:
 - Minimum pages = maximum pages in a single book
 - Maximum pages = sum of all pages

 For a given value 'mid':
 - We try to allocate books in order (contiguous manner)
 - If pages exceed 'mid', we move to the next student
 - We count how many students are required

 Binary Search Decision:
 - If required students <= m, allocation is possible,
   so we try smaller values
 - Otherwise, we increase the limit

 Final Answer:
 Minimum value of maximum pages per student
*/

#include <bits/stdc++.h>
using namespace std;

int countStudents(vector<int>& arr, int n, int limit) {
    int students = 1;
    int pages = 0;

    for (int i = 0; i < n; i++) {
        if (pages + arr[i] > limit) {
            students++;
            pages = arr[i];
        } else {
            pages += arr[i];
        }
    }
    return students;
}

int findPages(vector<int>& arr, int n, int m) {

    if (m > n) return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int requiredStudents = countStudents(arr, n, mid);
        if (requiredStudents <= m) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
