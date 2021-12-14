### [Text Justification](https://leetcode.com/problems/text-justification/) <br>

Given an array of strings `words` and a width `maxWidth`, format the text such that each line has exactly `maxWidth` characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces `' '` when necessary so that each line has exactly `maxWidth` characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left-justified and no extra space is inserted between words.

Note:

 - A word is defined as a character sequence consisting of non-space characters only.
 - Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
 - The input array words contains at least one word.
 



#### Example 1:

```
Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]

```

#### Example 2:

```
Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be", because the last line must be left-justified instead of fully-justified.
Note that the second line is also left-justified becase it contains only one word.

```

#### Example 3:

```
Input: words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], maxWidth = 20
Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]

```


# Solutions

### Python
```
class Solution:
    
    def fullJustify(self, words, maxWidth):
        n = len(words)
        L = maxWidth
        i = 0     # the index of the current word   
        ans = [] 
        
        def getKwords(i):
            k = 0 # figure out how many words can fit into a line
            l = ' '.join(words[i:i+k]) 
            while len(l) <= L and i+k <= n:
                k += 1
                l = ' '.join(words[i:i+k])
            k -= 1 
            return k
        
        
        def insertSpace(i, k):
            ''' concatenate words[i:i+k] into one line'''
            l = ' '.join(words[i:i+k])       
            if k == 1 or i + k == n:        # if the line contains only one word or it is the last line  
                spaces = L - len(l)         # we just need to left assigned it
                line = l + ' ' * spaces 
            else:                           
                spaces = L - len(l) + (k-1) # total number of spaces we need insert  
                space = spaces // (k-1)     # average number of spaces we should insert between two words
                left = spaces % (k-1)       # number of 'left' words, i.e. words that have 1 more space than the other words on the right side
                if left > 0:
                    line = ( " " * (space + 1) ).join(words[i:i+left])  # left words
                    line += " " * (space + 1)                           # spaces between left words & right words
                    line += (" " * space).join(words[i+left:i+k])       # right woreds
                else: 
                    line = (" " * space).join(words[i:i+k])
            return line
        

        while i < n: 
            k = getKwords(i)  
            line = insertSpace(i, k) # create a line which contains words from words[i] to words[i+k-1]
            ans.append(line) 
            i += k 
        return ans		
    
    
    
    
    
    
#     def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
#         res=[]
#         line=[]
#         line_len=0
#         n=len(words)
        
#         def words_join(line, line_len, is_last):
#             '''
#             Merges line array int string
#             and this output we append to res
#             '''
#             out=""
                        
#             spaces_count=len(line)-1
#             if len(line)==1:
#                 spaces_count=1
                
#             if is_last or len(line)==1:
#                 out=" ".join(line)
#                 out += " "*(maxWidth-len(out))
#             else:
#                 spaces_total_len = maxWidth - line_len
#                 each_len = spaces_total_len / spaces_count
                
#                 if each_len.is_integer():
#                     spaces = " "*int(each_len)
#                     for i in range(spaces_count):
#                         out += line[i]
#                         out += spaces
#                 else:
                    
#                     init_len = int(each_len)+1
#                     # Array of spaces length. it is longer at init
#                     arr_spaces=[init_len]*spaces_count
#                     current_len=init_len*spaces_count
                    
#                     # While loop to decrease spaces to make current_len==spaces_total_len
#                     i=len(arr_spaces)-1
#                     while i>=0 and current_len > spaces_total_len:
#                         arr_spaces[i] -= 1
#                         current_len -= 1
#                         i -= 1
                    
#                     for i in range(len(arr_spaces)):
#                         word=line[i]
#                         word += " "*arr_spaces[i]
#                         out += word
                        
#                 out += line[-1]
                
#             return out
        
#         # if one word
#         if n==1:
#             str_line=words_join(words, len(words[0]), True)
#             return [str_line]
            
#         for i in range(n-1):
#             cur=words[i]
#             nxt=words[i+1]
            
#             line_len += len(cur)
#             line.append(cur)
            
#             spaces_count=len(line)-1
            
#             # if line reach maximum
#             # and if not last line i<n-1
#             if line_len <= maxWidth and line_len+len(nxt)+spaces_count >= maxWidth and i<n-1:
#                 str_line=words_join(line, line_len, False)
#                 line=[]
#                 line_len=0
#                 res.append(str_line)
#             # last word
#             if i+1 == n-1: 
#                 line_len += len(nxt)
#                 line.append(nxt)
#                 str_line = words_join(line, line_len, True)
#                 res.append(str_line)
#                 break
            
#         return res

```
