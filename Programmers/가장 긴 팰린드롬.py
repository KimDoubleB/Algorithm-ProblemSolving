def checkPalindrome(string):
    for i in range(0, int(len(string)/2)):
        if string[i] != string[len(string)-1-i]:
            return False
    return True

    
def solution(s):
    for i in range(len(s), 0, -1):
        for j in range(0, len(s)):
            s2 = s[j:i+j]
            if checkPalindrome(s2):
                return len(s2)
            if i+j > len(s): break
    return 1