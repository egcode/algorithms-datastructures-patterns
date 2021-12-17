### [Sell Diminishing-Valued Colored Balls](https://leetcode.com/problems/sell-diminishing-valued-colored-balls/) <br>

You have an `inventory` of different colored balls, and there is a customer that wants `orders` balls of **any** color.

The customer weirdly values the colored balls. Each colored ball's value is the number of balls **of that color** you currently have in your `inventory`. For example, if you own `6` yellow balls, the customer would pay `6` for the first yellow ball. After the transaction, there are only `5` yellow balls left, so the next yellow ball is then valued at `5` (i.e., the value of the balls decreases as you sell more to the customer).

You are given an integer array, `inventory`, where `inventory[i]` represents the number of balls of the `i-th` color that you initially own. You are also given an integer `orders`, which represents the total number of balls that the customer wants. You can sell the balls **in any order**.

Return *the ***maximum*** total value that you can attain after selling `orders` colored balls.* As the answer may be too large, return it **modulo** `10^9 + 7`.



#### Example 1:
<img src="../../../../../images/1648jj.gif">

```
Input: inventory = [2,5], orders = 4
Output: 14
Explanation: Sell the 1st color 1 time (2) and the 2nd color 3 times (5 + 4 + 3).
The maximum total value is 2 + 5 + 4 + 3 = 14.

```

#### Example 2:

```
Input: inventory = [3,5], orders = 6
Output: 19
Explanation: Sell the 1st color 2 times (3 + 2) and the 2nd color 4 times (5 + 4 + 3 + 2).
The maximum total value is 3 + 2 + 5 + 4 + 3 + 2 = 19.

```

#### Example 3:

```
Input: inventory = [2,8,4,10,6], orders = 20
Output: 110

```

#### Example 4:

```
Input: inventory = [1000000000], orders = 1000000000
Output: 21
Explanation: Sell the 1st color 1000000000 times for a total value of 500000000500000000. 500000000500000000 modulo 109 + 7 = 21.

```



# Solutions

### Python
```
class Solution:
    
    # def maxProfit(self, inventory: List[int], orders: int) -> int:
    #     inventory.sort(reverse=True) # inventory high to low 
    #     inventory += [0]
    #     ans = 0
    #     k = 1
    #     for i in range(len(inventory)-1): 
    #         print("inventory[i]: "+str(inventory[i])+"  inventory[i+1]: "+str(inventory[i+1])+"  k: "+str(k)+" orders: "+str(orders))
    #         if k*(inventory[i] - inventory[i+1]) < orders: 
    #             diff=inventory[i] - inventory[i+1]
    #             ans += k*(inventory[i] + inventory[i+1] + 1)*(diff)//2 # arithmic sum 
    #             orders -= k*(inventory[i] - inventory[i+1])
    #         else: 
                # q, r = divmod(orders, k)
                # ans += k*(2*inventory[i] - q + 1) * q//2 + r*(inventory[i] - q)
                # return ans % 1_000_000_007
    #         k += 1
    
    
    def maxProfit(self, inventory: List[int], orders: int) -> int:
        '''
        Arithmetic series sum
      
         ( (s+e) * (d+1) ) // 2
         
    Where:
         s - start
         e - end
         d - difference
        
    Example:
        
        # `example1` with both start and end
        s=2
        e=8
        d=6
        ss=((s+e)*(d+1))//2
        print(ss)
        print(2+3+4+5+6+7+8)   
        
        # `example2` with substracted start
        s=2
        e=8
        d=6
        ss=((s+e+1)*d)//2
        print(ss)
        print(2+3+4+5+6+7+8-2)         
        
         
        '''
        inventory.sort(reverse=True)
        inventory.append(0)
        res=0
        k=1
        
        for i in range(len(inventory)-1):
            diff=inventory[i]-inventory[i+1]
            if k*diff < orders:
                s=inventory[i+1]
                e=inventory[i]
                prof=((((s+e)*(diff+1) )//2) - s)
                res += k * prof # example1. We subsract start, since it'll be processed later
                # res += k* (((s+e+1)*(diff) )//2) # example2.
                orders -= k*diff
            else:
                quotient, remainder = divmod(orders, k) # divmod(dividend, divisor)
                
                # quotient is the one that we treat as usual
                s=inventory[i]-quotient
                e=inventory[i]  
                d=e-s
                whole=k*((((s+e)*(d+1) )//2) - s) 
                
                # and the remainder
                sub=(s*remainder)
                
                res += whole + sub
                                
                return res % 1000000007
            k += 1

```
