### SETs
# Check if sets intersect
s1={1,2,3,4}
s2={4,5,6,7}
if set(s1).isdisjoint(s2):
    print("sets don't have intersection")
else:
    print("sets have intersection")


### Find sets intersections or union
s1={1,2,3,4}
s2={4,5,6,7}
set_union=s1.union(s2)
set_intersection=s1.intersection(s2)
print("Set union: "+str(set_union))
print("Set intersection: "+str(set_intersection))


# #### Frozenset, turn array into a hash
arr=[(1,2), (3,4), (7,8)]
t=tuple(arr)
some_set=set()
some_set.add(frozenset(t))
print(some_set)


#### CONCATENATE SETS
s1=set([1,2,3])
s2=set([4,5])
s3 = s1 | s2
print(s3)
s3 |= {555}
print(s3)
