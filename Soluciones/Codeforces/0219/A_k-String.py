k = int(input())
s = input()
cnt = {}
for c in s:
	if c not in cnt:
		cnt[c] = 0
	cnt[c] += 1
ans = []
for key,val in cnt.items():
	if val % k:
		print('-1')
		exit(0)
	ans += [key] * (val // k)
ans *= k
print(''.join(ans))
