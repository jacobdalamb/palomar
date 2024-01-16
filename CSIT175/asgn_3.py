import sys
print("Assignment 3\n* * The Wizard Game * *")

def displayGreeting():
    print("The Wizard will see you now.\nOK, let's get started\n")
    askQuestions()

def processQuestion(loop_counter, question):
    print(f"{loop_counter}. What kind of question is '{question}'?")

def askQuestions():
    name = input("What's your name? ")
    question = ""
    loop_counter = 0
    numOfQuestions = "Unknown"
    try:
        numOfQuestions = input("How many Questions do you want to ask the Wizard?")
        numOfQuestions = int(numOfQuestions)
        print(f"Hey {name}, You want to ask the Wizard {numOfQuestions} questions.")
    except ValueError:
        print(f"Error: {numOfQuestions} is not a valid number!")
        sys.exit("PROGRAM TERMINATED WITH ERROR")
    while loop_counter < numOfQuestions:
        if loop_counter >= numOfQuestions:
            print("You may not ask any more questions!")
        else:
            loop_counter += 1
            question = input("What's your question? ")
            if question.lower().strip() != "bye":
                processQuestion(loop_counter, question)
            else:
                break

playGame = input("Do you want to talk to the Wizard? (Yes or No) ")
if playGame.lower().strip() == "yes":
    displayGreeting()
else:
    print("The Wizard wants you to go away now!")

print("END OF PROGRAM")
