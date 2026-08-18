# output = []
def combination(items, index=0, current=[]):
    if index == len(items):
        # output.append(current)
        print(current)
        return 
    
    combination(items, index+1, current) # do not choose
    combination(items, index+1, current + [items[index]]) # choose
    
combination(['A','B','C'], 0, current=[])
# print(output)