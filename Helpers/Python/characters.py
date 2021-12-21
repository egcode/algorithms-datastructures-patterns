# # #### LETTERS TO Alphabet ARRAY
word='abczzz'
alphabet=[0]*26
for l in word:
    alphabet[ord(l)-ord('a')] += 1
print(alphabet)

##### Special characted for sting encoding/decoding
separator = chr(256) # SEPARATE with this special character
print(separator)
