![Screen Shot 2022-08-31 at 10 10 57 PM](https://user-images.githubusercontent.com/85970478/187823962-1f6436b0-bbc7-4f73-8c64-6b106f28147b.png)

# 

Mastermind is a strategic board game where user has to crack the secret hidden color pattern by making guesses. With each guess, the game will tell you that in your guessed pattern, how many colors are in the actual pattern and how many are not.

**Written In C++ with compiler G++ (MinGW.org GCC-6.3.0-1)**

**NetBeans IDE was used with Cygwin-Windows debugger**

# Game Rules

1. The user will have a maximum of 10 guesses to crack the pattern.
2. Before starting the game, user has to specify the length of the pattern he/she wants to crack.
3. Game also gives an option to allow color duplicates in a single game pattern. User has to select appropriate option to enable/disable duplicates.
4. To guess the color pattern, user has to enter the color codes from the available colors in game domain.
Available colors to choose from and their character representation:
<img width="353" alt="Screen Shot 2022-08-30 at 2 32 38 PM" src="https://user-images.githubusercontent.com/85970478/187526930-42aed298-50e0-4b62-8c89-533802140623.png">
For e.g. If you want to guess RED-GREEN-YELLOW-ORANGE for a 4-code length pattern, type only RGYO.
5. A) If a color in the guessed pattern is wrong, ‘-‘ will appear for that color.
   B) If a color in the guessed pattern is right but is at wrong position, ‘X’ code will appear for that color.
   C) If a color in the guessed pattern is right and, also at the correct position, ‘O’ code will appear for that color.
   
## Winning Condition
All the colors are guessed correctly in 10 moves i.e. O O O O pattern is formed on the console.

## Losing Condition
If all the moves are exhausted and you’re unable to guess the correct pattern.

# Game Play
## 1. User Instructions:
All the instructions and game rule will be notified to the user before game starts.

![image](https://user-images.githubusercontent.com/85970478/187520312-2e27ffe6-d550-4759-90ce-6855025c88f5.png)

## 2. Code Length:
User is asked to select the length of the pattern which he/she wants to use in the gameplay. User can choose any length from 1 to 8 by entering a valid input value. In case, user enters invalid value, the user will be asked to input the length again.

![image](https://user-images.githubusercontent.com/85970478/187527227-ada11f4b-92b4-49f2-8c04-ac27d71ca4ea.png)

## 3. Duplicate Allowance:
User will be given an option that does he/she wants to allow duplicates in the code pattern. He/she will be asked to enter 1 to allow, or 0 to not. In case, if user enters invalid input, then the user will be asked to input the length again. User will be given an option that does he/she wants to allow duplicates in the code pattern. He/she will be asked to enter 1 to allow, or 0 to not. In case, if user enters invalid input, then the user will be asked to input the length again.

![image](https://user-images.githubusercontent.com/85970478/187527289-77bdef63-c82f-4f7a-a468-cd9c6e776aed.png)

## 4. Entering Guesses:
User can choose any color code from the given color scheme. Validations are placed if user chooses invalid color code, or/and invalid code length.

![image](https://user-images.githubusercontent.com/85970478/187527402-5d7d5524-20b6-4704-ab35-514013da9171.png)

## 5. Gameboard Display:
With each guess entered, following configuration will appear telling the user about his/her progress in cracking the code.

![image](https://user-images.githubusercontent.com/85970478/187527474-d5be36a9-f82e-4e6d-8cfa-b1569cbbef04.png)

## 6. Game End:
After game ends, user will be notified about the status of his gameplay and correct pattern is displayed.

User lost scenario:

![image](https://user-images.githubusercontent.com/85970478/187527669-d0fc84c2-a4d4-4cb0-834d-1d584f72b9f2.png)

User won scenario:

![image](https://user-images.githubusercontent.com/85970478/187527730-674af47a-b23f-4962-b409-18d290c49b3f.png)
