from datetime import datetime, date
print("Assignment 6")
def getCurrentYear():
    year = date.today().year
    return year
def getShortName():
    while True:
        fullname = input("Enter your full name (middle name if applicable): ")
        if fullname == "":
            continue
        else:
            nameLen = len(fullname)
            firstInit = fullname[:1]
            spaceFound = False
            cntr = 0
            lastSpace = 0
            for char in fullname:
                cntr += 1
                if char == " ":
                    spaceFound = True
                    lastSpace = cntr
                if spaceFound == True:
                    lastname = fullname[lastSpace:nameLen]
                    shortName = firstInit + ". " + lastname
                    return shortName
                else:
                    shortName = fullname
                    return shortName
def getYearFounded():
    while True:
        foundingDate = input("Enter the founding date of your company (mm/dd/yyyy): ")
        try:
            date_object = datetime.strptime(foundingDate, "%m/%d/%Y")
            yearFounded = int(date_object.year)
            print(yearFounded)
            return yearFounded
        except ValueError:
            print("Invalid date format. Please try again.")
            continue
content = []
with open("A8_employees.txt", "r") as file:
    for line in file:
        line = line.replace("\n", "")
        content.append(line)
content.sort()
loop_counter = 0
for item in content:
    replacedItem = item.replace("*", ", ", 1)
    replacedItemLen = len(replacedItem)
    asteriskFound = False
    cntr = 0
    loop_counter += 1
    asterisk = 0
    for char in replacedItem:
        cntr += 1
        if char == "*":
            asteriskFound = True
            asterisk = cntr
        if asteriskFound == True:
            name = replacedItem[:asterisk - 1]
            number = replacedItem[asterisk:replacedItemLen]
            finalItem = str(loop_counter) + ". " + name + ": $" + number
while True:
    userprompt = input("Add or Remove Employee? (A, R, or Done): ")
    if userprompt.lower().strip() == "done":
        outfile = open("A8_employees.txt", "w")
        salaryDict = {}
        for item in content:
            outfile.write(item + "\n")
            data = item.split("*")
            lastname = data[0]
            firstname = data[1]
            salary = data[2]
            key = lastname + " " + firstname
            salaryDict = {key: salary}
        firstnameList = list(salaryDict.keys())
        firstnameList.sort()
        for key in firstnameList:
            print(key)
        outfile.close()
        break
    elif userprompt.lower().strip() == "a" or userprompt.lower().strip() == "r":
        EmployeeFirstName = input("Enter Employee First Name: ")
        EmployeeLastName = input("Enter Employee Last Name: ")
        EmployeeSalary = input("Enter Employee Salary: ")
        Employee = EmployeeLastName + "*" + \
            EmployeeFirstName + "*" + EmployeeSalary
        if userprompt.lower().strip() == "a":
            content.append(Employee)
            print(f"{EmployeeFirstName} {EmployeeLastName} has been added")
        elif userprompt.lower().strip() == "r":
            if Employee in content:
                content.remove(Employee)
                print(f"{EmployeeFirstName} {EmployeeLastName} has been removed")
            else:
                print(f"{EmployeeFirstName} {EmployeeLastName} {EmployeeSalary} is not in the system")
        else:
            print(f"{Employee} is not in the system")
    else:
        print("Invalid Entry, try again")
        continue
while True:
    lookForName = input("What is the name you are looking for?")
    if lookForName == " " or lookForName.lower().strip() == "done":
        print("End of Program")
