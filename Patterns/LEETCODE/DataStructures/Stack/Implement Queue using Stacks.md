### [Implement Queue using Stacks](https://leetcode.com/problems/implement-queue-using-stacks/) <br>

Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (`push`, `peek`, `pop`, and `empty`).

Implement the `MyQueue` class:

 - `void push(int x)` Pushes element `x` to the back of the queue.
 - `int pop()` Removes the element from the front of the queue and returns it.
 - `int peek()` Returns the element at the front of the queue.
 - `boolean empty()` Returns `true` if the queue is `empty`, false otherwise.

**Notes**:
 - You must use **only** standard operations of a stack, which means only `push to top`, `peek/pop from top`, `size`, and `is empty` operations are valid.
 - Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.



#### Example 1:

```
Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]

Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false

```


# Solutions

### Python
```
class MyQueue:

    def __init__(self):
        '''
        s1 - for writing
        s2 - for reading
        
        when we peek we write all s1 into s2 in reverse order,
        and peek and pop from s2
        
        '''
        self.s1=[]
        self.s2=[]

    def push(self, x: int) -> None:
        self.s1.append(x)

    def pop(self) -> int:
        self.peek()
        return self.s2.pop()

    def peek(self) -> int:
        if not self.s2:
            while self.s1:
                self.s2.append(self.s1.pop())
        return self.s2[-1]

    def empty(self) -> bool:
        return not self.s1 and not self.s2

```
