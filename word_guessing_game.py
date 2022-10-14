import random
secret_word = "clock" #if i had had multiple secret words idk how the hints would work, maybe diff hint list for every word but then how to know which word goes with which list when chosing word is random
guess = ''
guess_count = 0
hints = ['It is an object that is most probably in your house', 'It is not a living being', 'It isnt particularly useful nowadays'
'It is not a food item', 'It has a long history associated with it', 'It uses batteries', 'Uses glass as one of its materials']
random_hint = random.randint(0,8)  #change this if you're changing the number of hints

confirmation = input(print('''Secret word game lets go. You have to guess the secret word based on 7 hints, 
each given after an incorrect guess. Are you ready? Type y to play''')) #first letter of guess lowercase coz python is irritating like that

if confirmation == 'y':
        
    if guess_count < 8:
        print(hints[guess_count])
        guess = input(print("Enter your guess now! "))
        guess_count += 1
        if guess == secret_word:
            print("You won!")
            break              #breaks the loop so you dont have to make 7 forceful guesses
        else:
                pass               #continues the while loop every instance your answer doesnt match
    else :
        print("Sorry, you ran out of tries. You lose.")               
    print("It took you", guess_count, "guesses")
    if guess_count <= 3:
        print("Wow you're amazing you guessed it so fast!")
    else:
        print("not bad you still earned your victory")
    
else:
    print("i wish you'd played :(")
        
    

