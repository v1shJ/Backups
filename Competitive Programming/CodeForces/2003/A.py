def A(l, s):
    if len(s) < 2:
        return False
    if list(s) == list(set(s)):
        return True
    stepper = 2
    for i in range(0, l, stepper):
        for j in range(i+stepper, l-stepper, stepper):
            pass

    pass

t = int(input())
for i in range(t):
    l = int(input())
    s = input()
    print("Yes" if A(l, s) else "No")