### [Asteroid Collision](https://leetcode.com/problems/asteroid-collision/) <br>

We are given an array `asteroids` of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.



#### Example 1:

```
Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.

```

#### Example 2:

```
Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.

```

#### Example 3:

```
Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.

```

#### Example 4:

```
Input: asteroids = [-2,-1,1,2]
Output: [-2,-1,1,2]
Explanation: The -2 and -1 are moving left, while the 1 and 2 are moving right. Asteroids moving the same direction never meet, so no asteroids will meet each other.

```


# Solutions

### Python
```
class Solution:
#     def asteroidCollision(self, asteroids: List[int]) -> List[int]:
#         '''
#         Using loop
#         '''
        
#         n=len(asteroids)
#         if n<2: return asteroids

#         def collide(a1, a2):
#             if a1>0 and a2<0:
#                 return True
#             return False
        
#         res=[]
        
#         i=0
#         while i<len(asteroids)-1:
#             a1=asteroids[i]
#             a2=asteroids[i+1]
            
#             if collide(a1, a2):
#                 if abs(a1)==abs(a2):
#                     del asteroids[i]
#                     del asteroids[i]
#                     i -= 1
#                 elif abs(a1)<abs(a2):
#                     del asteroids[i]
#                     i -= 1
#                 elif abs(a1)>abs(a2):
#                     del asteroids[i+1]
                    
#                 if i<0:
#                     i=0
#             else:
#                 i += 1
        
#         return asteroids
        
        
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        '''
        Using Stack
        '''
        stack=[]
        
        def collide(a1, a2):
            return a1>0 and a2<0
        
        for ast in asteroids:
            if stack and collide(stack[-1]>0, ast): 
                
                to_con=False
                while stack and collide(stack[-1]>0, ast): 
                    if abs(stack[-1])<abs(ast):
                        stack.pop()
                        continue
                    if abs(stack[-1])==abs(ast):
                        stack.pop()
                        to_con=True
                    break
                    
                if to_con:
                    continue
                    
                if not stack or stack and not collide(stack[-1]>0, ast): 
                    stack.append(ast)        
                    
            else:
                stack.append(ast)        
        
        return stack

```
