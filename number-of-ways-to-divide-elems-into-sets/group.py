#################################################################
#desc: find the number of ways to divide series into diff sets
#author: zhpmatrix
#date: 2017-05-11
#################################################################

from itertools import combinations
def c(n,k):
	return len([val for val in combinations(range(n),k)])

n_max  = 1000
k_max  = 1000
mem = [[-1] * k_max for i in xrange(n_max + 1)]

def group(n,k):
	if k == 0:
		return 1 if n == 0 else 0
	#if mem[n][k] > 0:
	#	return mem[n][k]
	res = 0
	for i in xrange(1, n - (k-1) + 1):
		res += group(n-i,k-1)*c(n,i)
	#mem[n][k] = res
	return res

if __name__ == '__main__':
	print group(4,3)
