# DNA Analysis Program (C++)

This C++ program is designed to analyze DNA sequences stored in the "dataset.txt" file. It provides various functionalities for processing and analyzing DNA data. Below, you will find an overview of the program, its structure, and how to use it.

## Project Structure

### Main Program (main.cpp)

- The `main.cpp` file contains the main program logic.
- It defines a class `App` that encapsulates DNA sequence-related methods and data structures.
- The program performs operations such as data input, character counting, ASCII conversion, binary representation, distance calculation, encryption/decryption, and more.

### DNA Dataset (dataset.txt)

- The `dataset.txt` file stores DNA sequences and their corresponding IDs.
- Each DNA sequence is preceded by a unique ID enclosed within angle brackets (e.g., `<0000001>`).
- The dataset includes a total of 51 DNA sequences, each consisting of uppercase letters.

## Available Operations

1. **Input**: Reads DNA sequence data from the "dataset.txt" file.
2. **Output**: Displays information about a specific DNA sequence by its ID.
3. **Count**: Counts the occurrences of characters in each DNA sequence.
4. **Convert**: Converts characters in DNA sequences to their ASCII values.
5. **Binary**: Converts ASCII values to binary representation.
6. **Detect**: Sets a target DNA sequence for comparison.
7. **Compare**: Compares the target DNA sequence with other sequences and calculates similarity.
8. **Search**: Finds DNA sequences with the maximum similarity to the target.
9. **Distance**: Calculates Euclidean, Manhattan, and Minkowski distances between DNA sequences.
10. **Encrypt**: Encrypts DNA sequences using the Caesar cipher algorithm.
11. **Decrypt**: Decrypts a specific DNA sequence previously encrypted.
12. **Save**: Saves the analysis results to a file.
13. **Exit**: Exits the program.

## Usage

- The program is interactive and menu-driven. Users can choose operations by entering a corresponding number.
- It reads DNA sequence data from the "dataset.txt" file and provides various analyses and transformations based on user input.
- Users can specify a target DNA sequence for comparison, calculate distances between sequences, and perform encryption/decryption.

## Note

- The program assumes that DNA sequences are stored in a specific format in the "dataset.txt" file, with IDs and DNA sequences separated by newline characters.

This program provides a range of functionalities for working with DNA sequences and can be used for various DNA analysis tasks.

