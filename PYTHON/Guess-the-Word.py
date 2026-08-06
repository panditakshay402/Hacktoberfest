import random

def guess_the_word():
    words = ["python", "javascript", "hangman", "programming", "developer"]
    secret_word = random.choice(words)  # Randomly choose a word from the list
    guessed_letters = []
    attempts = 6  # Number of allowed incorrect attempts
    word_display = "_" * len(secret_word)

    print("Welcome to 'Guess the Word'!")
    print(f"The word has {len(secret_word)} letters: {word_display}")

    while attempts > 0 and "_" in word_display:
        guess = input("Guess a letter: ").lower()

        if len(guess) != 1 or not guess.isalpha():
            print("Please enter a single valid letter.")
            continue

        if guess in guessed_letters:
            print("You've already guessed that letter. Try again.")
            continue

        guessed_letters.append(guess)

        if guess in secret_word:
            word_display = ''.join(
                [guess if secret_word[i] == guess else word_display[i] for i in range(len(secret_word))]
            )
            print(f"Good guess! Current word: {word_display}")
        else:
            attempts -= 1
            print(f"Wrong guess! You have {attempts} attempts left.")

    if "_" not in word_display:
        print(f"Congratulations! You've guessed the word: {secret_word}")
    else:
        print(f"Game over! The secret word was: {secret_word}")

# Start the game
guess_the_word()
