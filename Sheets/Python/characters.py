# # #### LETTERS TO Alphabet ARRAY
word='abczzz'
alphabet=[0]*26
for l in word:
    alphabet[ord(l)-ord('a')] += 1
print(alphabet) # [1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3]
#                  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z

##### Special characted for sting encoding/decoding
separator = chr(256) # SEPARATE with this special character
print(separator) # Ā
