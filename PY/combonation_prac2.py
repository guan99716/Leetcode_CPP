def combination_dfs(items, index, current=None):
    n = len(items)
    if index == n:
        print(current)
        return
    combination_dfs(items, index + 1, current)  # do not choose
    combination_dfs(items, index + 1, current + [items[index]])  # choose


combination_dfs(['A','B','C'], 0, [])