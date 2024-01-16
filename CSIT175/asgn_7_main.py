from asgn_7_module import Car, Model_1, Model_2
import random
def main():
    print("Let the Race Begin!")
    print("* * The first car to 50 wins * *")
    myCar = Model_1()
    print(f"Your car is Model 1 and the color is {myCar.getColor()}")
    myCar.soundHorn()
    computerCar = Model_2()
    print(f"Your car is Model 2 and the color is {computerCar.getColor()}")
    computerCar.soundHorn()
    while True:
        randomNum1 = random.randint(1, 5)
        randomNum2 = random.randint(1, 5)
        myCarDistance = myCar.showLine(randomNum1)
        computerCarDistance = computerCar.showLine(randomNum2)
        myCarDistanceLength = len(myCarDistance)
        computerCarDistanceLength = len(computerCarDistance)
        print(f"({myCar.getColor()}) {myCarDistance}> ({myCarDistanceLength})")
        print(f"({computerCar.getColor()}) {computerCarDistance}>({computerCarDistanceLength})")
        if myCarDistanceLength >= 50 or computerCarDistanceLength >= 50:
            if myCarDistanceLength >= 50 and computerCarDistanceLength >= 50:
                if myCarDistanceLength == computerCarDistanceLength:
                    print("Both the Computer and You Tied!")
                    break
                elif myCarDistanceLength >= computerCarDistanceLength:
                    print("You Won!")
                    break
                else:
                    print("The Computer Wins!")
                    break
            elif computerCarDistanceLength >= 50:
                print("The Computer Wins!")
                break
            else:
                print("You Won!")
                break
        prompt = input("Drive some more? (y/n): ")
        if prompt == "y" or prompt == "":
            continue
        else:
            break
    if __name__ == "__main__":
        main()
