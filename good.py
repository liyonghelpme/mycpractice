#coding:utf8
S = 10
n = 3
price = [5, 4, 2]

def zeros(row, col):
    return [[0 for c in xrange(0, col)] for i in xrange(0, row)]
def zeroOneKnapsack(price, S):
    #花费矩阵
    c = []
    n = len(price)
    c = zeros(n, S+1)
    for i in xrange(0, n):
        for j in xrange(0, S+1):
            if price[i] > j:
                c[i][j] = c[i-1][j]
            else:
                c[i][j] = max(c[i-1][j], price[i]+c[i-1][j-price[i]])
    return c[n-1][S]

print(zeroOneKnapsack(price, S))
