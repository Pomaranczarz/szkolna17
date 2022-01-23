def dwumianREK(n, k):
    if k == 0 or k == n:
        return 1
    else:
        return n/k * dwumianREK(n-1, k-1)
