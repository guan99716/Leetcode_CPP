def combination(items):
    n = len(items)
    for mask in range(1 << n):
        subset = [items[i] for i in range(n) if mask & (1 << i)]
        print(subset)

combination(['A','B','C'])