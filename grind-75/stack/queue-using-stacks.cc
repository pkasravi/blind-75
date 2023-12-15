/* -----------------------------------------------------------------------------
 * Link: https://leetcode.com/problems/implement-queue-using-stacks/
 * 
 * Solution Description:
 * We will use two stacks to represent input and output buffers. As items come
 * in we push them into our input buffer. When peek/pop is called we use our
 * output buffer, if our output buffer is empty we move all items from our input
 * buffer to our output buffer thereby reversing the order.
 *
 * Steps:
 * 1 - Create two stacks in constructor
 * 2 - On push simply push into output buffer
 * 3 - On peek & pop, check if output buffer is empty. If no then simply pop
 *     from output buffer. Otherwise copy all items from input buffer to output
 *     buffer and then pop.
 *
 * Complexity Analysis:
 * Time: Since items are only ever reversed (copied from input to output) once, the 
 * popping or peeking is O(n) in the worst case and O(1) amortized or in the
 * average case. Pushing is always O(1).
 * Space: O(n) for our two stacks holding the items
 *
 * -----------------------------------------------------------------------------
 */

class MyQueue {
 public:
   MyQueue() : input_{}, output_{} {}
   
   void push(int x) {
     input_.push(x);
   }
   
	 std::optional<int> pop() {
     if (empty()) {
       return {};
     }
     if (output_.empty()) {
       fill_output();
     }
     const auto val{output_.top()};
     output_.pop();
     return val;
   }
   
   std::optional<int> peek() {
     if (empty()) {
       return {};
     }
     if (output_.empty()) {
       fill_output();
     }
     return output_.top();
   }
   
   bool empty() {
     return input_.empty() && output_.empty();
   }
 
 private:
   void fill_output() {
     while (!input_.empty()) {
       const auto val{input_.top()};
       input_.pop();
       output_.push(val);
     }
   }
   std::stack<int> input_;
   std::stack<int> output_;
};
