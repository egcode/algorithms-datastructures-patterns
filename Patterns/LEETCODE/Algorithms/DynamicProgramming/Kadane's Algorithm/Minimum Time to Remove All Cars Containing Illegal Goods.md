### [Minimum Time to Remove All Cars Containing Illegal Goods](https://leetcode.com/problems/minimum-time-to-remove-all-cars-containing-illegal-goods/) <br>

You are given a **0-indexed** binary string s which represents a sequence of train cars. `s[i] = '0'` denotes that the `i-th` car does **not** contain illegal goods and `s[i] = '1'` denotes that the `i-th` car does contain illegal goods.

As the train conductor, you would like to get rid of all the cars containing illegal goods. You can do any of the following three operations **any** number of times:

 - Remove a train car from the **left** end (i.e., remove `s[0]`) which takes 1 unit of time.
 - Remove a train car from the **right** end (i.e., remove `s[s.length - 1]`) which takes 1 unit of time.
 - Remove a train car from **anywhere** in the sequence which takes 2 units of time.

Return *the ***minimum*** time to remove all the cars containing illegal goods*.

Note that an empty sequence of cars is considered to have no cars containing illegal goods.



#### Example 1:

```
Input: s = "1100101"
Output: 5
Explanation: 
One way to remove all the cars containing illegal goods from the sequence is to
- remove a car from the left end 2 times. Time taken is 2 * 1 = 2.
- remove a car from the right end. Time taken is 1.
- remove the car containing illegal goods found in the middle. Time taken is 2.
This obtains a total time of 2 + 1 + 2 = 5. 

An alternative way is to
- remove a car from the left end 2 times. Time taken is 2 * 1 = 2.
- remove a car from the right end 3 times. Time taken is 3 * 1 = 3.
This also obtains a total time of 2 + 3 = 5.

5 is the minimum time taken to remove all the cars containing illegal goods. 
There are no other ways to remove them with less time.

```

#### Example 2:

```
Input: s = "0010"
Output: 2
Explanation:
One way to remove all the cars containing illegal goods from the sequence is to
- remove a car from the left end 3 times. Time taken is 3 * 1 = 3.
This obtains a total time of 3.

Another way to remove all the cars containing illegal goods from the sequence is to
- remove the car containing illegal goods found in the middle. Time taken is 2.
This obtains a total time of 2.

Another way to remove all the cars containing illegal goods from the sequence is to 
- remove a car from the right end 2 times. Time taken is 2 * 1 = 2. 
This obtains a total time of 2.

2 is the minimum time taken to remove all the cars containing illegal goods. 
There are no other ways to remove them with less time.

```


# Solutions

### Python
```
class Solution:
    def minimumTime(self, s: str) -> int:
        '''
        Kadane's Algorithm.
        We replace all `0`s to `-1` and we get  53. Maximum Subarray problem
        '''
        s1=[-1 if ch=='0' else 1 for ch in s]
        n=len(s1)
        
        def maxSubArray(nums):
            '''
            The difference here we take the minumum instead of max
            '''
            best_sum=nums[0]
            current_sum=nums[0]

            for num in nums[1:]:
                current_sum=min(num, current_sum + num)
                best_sum=min(best_sum, current_sum)
            return best_sum
        
            
        return min(0, maxSubArray(s1)) + n

    def minimumTime(self, s: str) -> int:
        '''
        
        "01001010" - original
        
         02224466  - right
         66444220  - left    
         12345678  - count right
         87654321  - count left
       
        '''
        n=len(s)
        
        left=[0]*n
        left[-1]=2 if s[-1]=='1' else 0
        for i in range(n-1)[::-1]:
            left[i]=left[i+1]+(2 if s[i]=='1' else 0)
            
        right=0
        res=float('inf')
        for i in range(n):
            if s[i]=='1':
                right = min(right+2, i+1) # `right` and `count right`
            res=min(res, right+left[i], right+n-i-1) # `right` and `left`   `right` and `count left`
            
            
        return res


```
