num = 0
while num != -1:
  num = int(input("Number: "))
  print("Is", num % 7, "good?")
  test = input()
  while (test == "no"):
    num = (num + (5 - (num %5))) % 7
    print("Is", num % 7, "good?")
    test = input()
