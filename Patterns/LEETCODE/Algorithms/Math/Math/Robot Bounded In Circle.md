### [Robot Bounded In Circle](https://leetcode.com/problems/robot-bounded-in-circle/) <br>

On an infinite plane, a robot initially stands at `(0, 0)` and faces north. The robot can receive one of three instructions:

 - `"G"`: go straight 1 unit;
 - `"L"`: turn 90 degrees to the left;
 - `"R"`: turn 90 degrees to the right.

The robot performs the `instructions` given in order, and repeats them forever.

Return `true` if and only if there exists a circle in the plane such that the robot never leaves the circle.

 

#### Example 1:

```
Input: instructions = "GGLLGG"
Output: true
Explanation: The robot moves from (0,0) to (0,2), turns 180 degrees, and then returns to (0,0).
When repeating these instructions, the robot remains in the circle of radius 2 centered at the origin.

```

#### Example 2:

```
Input: instructions = "GG"
Output: false
Explanation: The robot moves north indefinitely.

```
#### Example 3:

```
Input: instructions = "GL"
Output: true
Explanation: The robot moves from (0, 0) -> (0, 1) -> (-1, 1) -> (-1, 0) -> (0, 0) -> ...

```


# Solutions

### Python
```
class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        '''
        
        The robot stays in the circle if POSITION or ORIENTATION don't change:
        - It's returns to [0,0] - no POSITION change
        or
        - It's not pointing to North (Initial Direction) - no ORIENTATION change
        
        '''
        pos=[0,0] 
        dirs=[[0,1],[1,0],[0,-1],[-1,0]] # [ top, right, down, left ]
        current_dir=0 # top
        
        for ins in instructions:
            if ins=="G":
                pos[0] += dirs[current_dir][0]
                pos[1] += dirs[current_dir][1]
            elif ins=="R":
                current_dir = (current_dir+1)%4
            elif ins=="L":
                current_dir = (current_dir+3)%4
                
        if pos==[0,0] or current_dir != 0:
            return True
        return False

```
