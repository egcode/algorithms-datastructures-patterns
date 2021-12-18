### [Min Stack](https://leetcode.com/problems/min-stack/) <br>

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the `MinStack` class:

 - `MinStack()` initializes the stack object.
 - `void push(int val)` pushes the element `val` onto the stack.
 - `void pop()` removes the element on the top of the stack.
 - `int top()` gets the top element of the stack.
 - `int getMin()` retrieves the minimum element in the stack.


#### Example 1:

```
Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2

```



# Solutions

### Python
```
class MinStack:

#     def __init__(self):
#         '''
#         We store minimum (value, currentMinimum) tuple in the stack
#         '''
#         self.stack=[]

#     def push(self, x: int) -> None:
#         cur_min=float('inf')
#         if self.stack:
#             cur_min=self.stack[-1][1]
#         self.stack.append((x, min(cur_min, x)))

#     def pop(self) -> None:
#         self.stack.pop()

#     def top(self) -> int:
#         return self.stack[-1][0]

#     def getMin(self) -> int:
#         return self.stack[-1][1]
        
        
    def __init__(self):
        '''
        Idea is the same as above but with two stacks
        self.stack - stores regular values
        self.stack_mins - stores minimums
        
        On pop: 
         - Pop from self.stack as regular. 
         - For self.stack_mins we check if value is the same as top of Stack2        
        '''
        self.stack=[]
        self.stack_mins=[]

    def push(self, x: int) -> None:
        self.stack.append(x)
        if self.stack_mins:
             if self.stack_mins[-1]>=x:
                    self.stack_mins.append(x)
        else:
            self.stack_mins.append(x)

    def pop(self) -> None:
        if self.stack[-1] == self.stack_mins[-1]:
            self.stack_mins.pop()
        self.stack.pop()
        
    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.stack_mins[-1]

```
