def corr(t):
    r = []

    for i in range(0, len(t)):
        if t[i] == '(' or t[i] == '[' or t[i] == '{':
            r.append(t[i])
        else:
            if not r:
                return False
            else:
                if t[i] == ')':
                    if r[-1] == '(':
                        r.pop()
                elif t[i] == ']':
                    if r[-1] == '[':
                        r.pop()
                elif t[i] == '}':
                    if r[-1] == '{':
                        r.pop()
                    
    if not r:
        return True
    else:
        return False
    
def solution(s):
    answer = 0
    
    for i in range(0, len(s)):
        input = s[i:]
        input = input + s[0:i]
        #print(input)
        rst = corr(input)
        
        if rst == True:
            answer += 1
    
    return answer