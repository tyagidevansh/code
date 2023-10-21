def minion_game2(string):

    vowels = "AEIOU"
    sub_vow = []
    sub_con = []
    
    for i in range(len(string)):
        for j in range(len(string)+1):
            if string[i] in vowels:
                sub_vow.append(string[i:j])
               # print("vowel:", sub_vow)
            else:
                sub_con.append(string[i:j])
                #print("consonants: ", sub_con)

    sub_vow = [word for word in sub_vow if word != '']
    sub_con = [word for word in sub_con if word != '']

    stuart_score = len(sub_con)
    kevin_score = len(sub_vow)
    
    if stuart_score > kevin_score:
        print("Stuart", stuart_score)
    elif kevin_score > stuart_score:
        print("Kevin", kevin_score)
    else:
        print("Draw")
        
def minion_game(string):
    vowels = "AEIOU"
    stuart_score = 0
    kevin_score = 0
    length = len(string)
    
    for i in range(length):
        if string[i] in vowels:
            kevin_score += length - i
        else:
            stuart_score += length - i
            
    if stuart_score > kevin_score:
        print("Stuart", stuart_score)
    elif kevin_score > stuart_score:
        print("Kevin", kevin_score)
    else:
        print("Draw")
    

if __name__ == '__main__':
    s = input()
    minion_game(s)