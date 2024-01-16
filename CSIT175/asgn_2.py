print('Assignment 2\n* * The Wizard Game * *')

def displayGreeting():
    print("The Wizard will see you now.\nOkay let's ges started.")
    askQuestions()

def askQuestions():
    name = input("What's your name? ")
    question = ''
    while question != 'bye':
        question = input("What's your question? ")
        if question != 'bye':
            print(f'What kind of question is {question}?')
        else:
            print('bye!')

playGame = input('Do you want to talk to the Wizard? (yes or no) ')
if playGame == 'yes':
    displayGreeting()
else:
    print("The Wizard wants you to go away now!")
    print('END OF PROGRAM')
