# Word Frequency Counter

This program is a C implementation of a word frequency counter. It prompts the user to enter the name of a text file, reads the file, and displays the ten most frequently used words in the text.

## How it Works

1. The program starts by asking the user to enter the filename of the text file they want to analyze.

2. It opens the file using the `fopen()` function and checks if the file was successfully opened. If the file cannot be opened, an error message is displayed, and the program terminates.

3. The program reads each word from the file using the `fscanf()` function. It converts each word to lowercase using the `convertToLowercase()` function to ensure case-insensitive word comparison.

4. The program checks if the word is a delimiter (such as space, tab, newline, or punctuation marks). If the word is not a delimiter, it searches for the word in the `wordList` array using the `isWordInList()` function.

5. If the word is not found in the `wordList`, it is added to the list along with an initial frequency of 1 using the `insertWordToList()` function. If the word is already present in the list, the frequency is incremented using the `updateWordFrequency()` function.

6. After reading all the words from the file, the program sorts the `wordList` array based on word frequency using the `qsort()` function and the `compareWordFrequency()` function as the comparison criterion.

7. Finally, the program displays the ten most frequently used words along with their occurrences in the text.

## Getting Started

To run this program locally, follow these steps:

1. Clone this repository to your local machine.

   ```
   git clone https://github.com/your-username/word-frequency-counter.git
   ```

2. Compile the program using a C compiler.

   ```
   gcc -o word_frequency word_frequency.c
   ```

3. Run the program.

   ```
   ./word_frequency
   ```

4. Enter the filename of the text file you want to analyze when prompted.

5. The program will display the ten most frequently used words in the text.

## Contributing

Contributions are welcome! If you have any suggestions or improvements for this program, please open an issue or submit a pull request.

## License

This program is licensed under the [MIT License](LICENSE).
