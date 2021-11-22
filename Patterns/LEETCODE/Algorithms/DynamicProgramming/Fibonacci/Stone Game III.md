### [Stone Game III](https://leetcode.com/problems/stone-game-iii/) <br>

Alice and Bob continue their games with piles of stones. There are several stones **arranged in a row**, and each stone has an associated value which is an integer given in the array `stoneValue`.

Alice and Bob take turns, with **Alice** starting first. On each player's turn, that player can take **1, 2 or 3 stones** from the **first** remaining stones in the row.

The score of each player is the sum of values of the stones taken. The score of each player is 0 initially.

The objective of the game is to end with the highest score, and the winner is the player with the highest score and there could be a tie. The game continues until all the stones have been taken.

Assume Alice and Bob **play optimally**.

Return **"Alice"** if Alice will win, **"Bob"** if Bob will win or **"Tie"** if they end the game with the same score.



#### Example 1:

```
Input: values = [1,2,3,7]
Output: "Bob"
Explanation: Alice will always lose. Her best move will be to take three piles and the score become 6. Now the score of Bob is 7 and Bob wins.

```

#### Example 2:

```
Input: values = [1,2,3,-9]
Output: "Alice"
Explanation: Alice must choose all the three piles at the first move to win and leave Bob with negative score.
If Alice chooses one pile her score will be 1 and the next move Bob's score becomes 5. The next move Alice will take the pile with value = -9 and lose.
If Alice chooses two piles her score will be 3 and the next move Bob's score becomes 3. The next move Alice will take the pile with value = -9 and also lose.
Remember that both play optimally so here Alice will choose the scenario that makes her win.

```


#### Example 3:

```
Input: values = [1,2,3,6]
Output: "Tie"
Explanation: Alice cannot win this game. She can end the game in a draw if she decided to choose all the first three piles, otherwise she will lose.

```


#### Example 4:

```
Input: values = [1,2,3,-1,-2,-3,7]
Output: "Alice"

```


#### Example 5:

```
Input: values = [-1,-2,-3]
Output: "Tie"

```


# Solutions

### Python
```
class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        '''
        Explanation here:
            https://www.youtube.com/watch?v=CWTjs46kl5U
        
        Dp Problem: 
                -dp[i] stores the BEST difference (aliceScore - bobScore)
                -we loop from the end of array and pick best (aliceScore - bobScore) from three Alice's options 
                -dp[0] if positive, that means Alice could win

        Example:
        [5,6,7]
        alice has 5, bob has 13, diff is -8
        alice has 11, bob has 7, diff 4
        alice has 18, bob has 0, diff is 18
                     0 1 2
        stoneList = [5,  6,  7]
            dp    = [18, 13, 7, 0]
            
            if dp[0]>0 Alice could win 

        
        '''
        
        n=len(stoneValue)
        dp=[0]*(n+1)
        
        for i in reversed(range(n)):
            opt_1 = stoneValue[i]-dp[i+1] # Alice takes one stone
            
            opt_2 = opt_1
            if i<(n-1): 
                opt_2 = (stoneValue[i]+stoneValue[i+1]) - dp[i+2] # Alice takes two stones
            
            opt_3 = opt_2
            if i<(n-2):
                opt_3 = (stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]) - dp[i+3] # Alice takes three stones
            
            
            dp[i]=max(opt_1, opt_2, opt_3)
            
        
        if dp[0]==0:
            return "Tie"
        elif dp[0]>0:
            return "Alice"
        else:
            return "Bob"

```
