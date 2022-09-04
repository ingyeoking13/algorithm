temp = 0
ans = []
d = int(input())
while True:
	if '666' in str(temp):
		ans.append(temp)
		if len(ans) == int(d):
			print(temp)
			break
	temp+=1