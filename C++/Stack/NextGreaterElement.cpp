#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector < int > nextGreaterElements(vector < int > & nums) {
    int n = nums.size();
    vector < int > nge(n, -1);  // Initialize a vector to store the next greater elements, initially set to -1
    stack < int > st;  // Initialize a stack to store indices of elements in 'nums'

    // Traverse the 'nums' array in reverse order (circularly)
    for (int i = 2 * n - 1; i >= 0; i--) {
      while (!st.empty() && st.top() <= nums[i % n]) {
        st.pop();  // Pop elements from the stack if they are smaller than or equal to the current element
      }

      if (i < n) {
        if (!st.empty()) {
          nge[i] = st.top();  // If there is a greater element in the stack, update nge[i] with its value
        }
      }
      st.push(nums[i % n]);  // Push the current element's value into the stack
    }
    return nge;  // Return the vector containing the next greater elements
  }
};

int main() {
  Solution obj;
  vector < int > v {5,7,1,2,6,0};
  vector < int > res = obj.nextGreaterElements(v);
  cout << "The next greater elements are" << endl;
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";  // Print the next greater elements
  }
}
