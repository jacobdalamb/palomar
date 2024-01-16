import asgn_5_module as mod
print("Assignment 5")
def main():
    playGame = input("Do you want to talk to the Wizard? (Yes or No) ")
    if playGame.lower().strip() == "yes":
        mod.displayGreeting()
        mod.askQuestions()
    else:
        print("The Wizard wants you to go away now!")
        print("END OF PROGRAM")
if __name__ == "__main__":
    main()
