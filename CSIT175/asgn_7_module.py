class Car:
    def __init__(self, distance=2, horn="beep beep", color="", line="-"):
        self.__distance = distance
        self.__horn = horn
        self.__color = color
        self.__line = line
    def soundHorn(self):
        print(self.__horn)
    def getColor(self):
        return self.__color
    def showLine(self, distance):
        for i in range(distance):
            self.__line += "-"
            return self.__line
class Model_1(Car):
    def __init__(self):
        Car.__init__(self, distance=2, horn="beep beep", color="", line="-")
        self.__color = "blue"
    def getColor(self):
        return self.__color
class Model_2(Car):
    def __init__(self):
        Car.__init__(self, distance=2, horn="honk honk", color="", line="-")
        self.__color = "red"
    def getColor(self):
        return self.__color
