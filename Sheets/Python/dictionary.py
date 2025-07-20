### # Dictionary from range
n=5
dist = {i: float('inf') for i in range(1, n+1)}
print(dist) # {1: inf, 2: inf, 3: inf, 4: inf, 5: inf}


# add 1 to a value in a dictionary (map) if the key exists, or set it to 1 if it doesn't
my_map = {}
key = 'apple'
my_map[key] = my_map.get(key, 0) + 1
