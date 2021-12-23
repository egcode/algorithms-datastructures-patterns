# Sort By tuple element
t=[[4,5],[1,4],[0,1]]
t.sort(key=lambda tup: tup[0]) 
print("Sorted Tuple: " + str(t)) # Sorted Tuple: [[0, 1], [1, 4], [4, 5]]

print(60*"-")

# Sort string
some_str = "defbgca"
str_sorted="".join(sorted(some_str))
print("Sorted string: " + str_sorted) # Sorted string: abcdefg

print(60*"-")

