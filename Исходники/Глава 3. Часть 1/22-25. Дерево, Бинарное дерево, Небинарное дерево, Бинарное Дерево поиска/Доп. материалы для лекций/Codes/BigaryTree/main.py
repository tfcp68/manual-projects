a = int(input())
f = 1
for i in range(1,a+1):
    f*=i
for i in range(a-5):
    f*=a
print(f)