import random
def displayGreeting():
    print("\nThe Wizard will see you now.\n\nOK, let's get started\n")
def checkNumOfQuestions():
    numOfQuestions = input("How many Questions do you want to ask the Wizard? ")
    if numOfQuestions.isnumeric():
        numOfQuestions = int(numOfQuestions)
        numOfQuestions += 1
        print(f"I am giving you a bonus, you can ask {numOfQuestions} questions!\n")
    else:
        print(f"Warning: {numOfQuestions} is NOT a valid number. I am changing it to5\n")
        numOfQuestions = 5
    return numOfQuestions
def checkAge(name):
    while True:
        age = input("What is your age? ")
        if age.isnumeric():
            age = int(age)
            if age < 10 or age > 80:
                print(f"{name}, please enter a valid age between 10 and 80\n")
                continue
            elif age > 30 and age < 50:
                print(f"{name}, these are prime earning years\n")
                return age
            else:
                print(f"{name}, you are a good age to play this game\n")
                return age
        else:
            print("please enter a valid integer for your age")
def loadAnswers():
    answerFileList = []
    while True:
        filename = input("What is the name of the file that contains the Wizards potential answers? ")
        try:
            with open(filename, "r") as file:
                for line in file:
                    line = line.replace("\n", "")
                    answerFileList.append(line)
                    return answerFileList
        except FileNotFoundError:
            print(f"Error: {filename} Not Found")
            continue

def askQuestions():
    name = input("What's your name? ")
    age = checkAge(name)
    numOfQuestions = checkNumOfQuestions()
    answerFileList = loadAnswers()
    question = ""
    loop_counter = 0
    for loop_counter in range(numOfQuestions):
        loop_counter += 1
        question = input("\nWhat's your question? ")
        if question == "":
            print("You should enter a question")
            continue
        elif question.lower().strip() == "bye":
            break
        else:
            wizardFinalAnswer = processQuestion(loop_counter, question, answerFileList)
            print(wizardFinalAnswer)
    print("\nNo more questions for you!\nStop bothering the Wizard!\n")
def processQuestion(loop_counter, question, answerFileList):
    KeyWordList = ["Who", "What", "Where", "When", "Why", "How"]
    wizardAnswerList = []
    for keyword in KeyWordList:
        if question.startswith(keyword):
            wizardAnswerList = getWizardAnswers(keyword, answerFileList, wizardAnswerList)
            break
    count = len(wizardAnswerList)
    if count > 0:
        random.shuffle(wizardAnswerList)
        wizardFinalAnswer = (str(loop_counter) + ". The Wizard answers: " + wizardAnswerList[0])
    else:
        wizardFinalAnswer = str(loop_counter) + ". The Wizard answers: I don't know"
    return wizardFinalAnswer
def getWizardAnswers(keyword, answerFileList, wizardAnswerList):
    while True:
        for line in answerFileList:
            line_keywords = line.split("*")
            line_keyword = line_keywords[0]
            line_wizard_answer = line_keywords[1]
            if line_keyword == keyword:
                wizardAnswerList.append(line_wizard_answer)
                return wizardAnswerList
