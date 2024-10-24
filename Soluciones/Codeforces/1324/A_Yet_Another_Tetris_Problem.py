def solve():
	n = int(input())
	a = list(map(int,input().split()))
	for x in a:
		if (x-a[0]) % 2:
			print('NO')
			return
	print('YES')

for _ in range(int(input())):
	solve()
