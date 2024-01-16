print("Assignment 1")
name = input("What is your name? ")
age = int(input("What is your age? "))
daily_sleep_hours = float(input("How many hours do you sleep per day? "))
wasted_years = (daily_sleep_hours/24) * age
print(f"Hello {name}")
print(f"You have been unconscious for {wasted_years} years!")
