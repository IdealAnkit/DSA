import random

def rock_paper_scissors():
    print("🪨 Rock, 📄 Paper, ✂️ Scissors Game")
    choices = ['rock', 'paper', 'scissors']
    
    while True:
        user_choice = input("Choose rock, paper, or scissors (or type 'exit' to quit): ").lower()
        
        if user_choice == 'exit':
            print("Thanks for playing! 👋")
            break
        if user_choice not in choices:
            print("Invalid choice. Try again.")
            continue
        
        computer_choice = random.choice(choices)
        print(f"Computer chose: {computer_choice}")
        
        if user_choice == computer_choice:
            print("It's a tie!")
        elif (user_choice == 'rock' and computer_choice == 'scissors') or \
             (user_choice == 'paper' and computer_choice == 'rock') or \
             (user_choice == 'scissors' and computer_choice == 'paper'):
            print("You win! 🎉")
        else:
            print("You lose! 😢")
        print("-" * 30)

# Run the game
rock_paper_scissors()

