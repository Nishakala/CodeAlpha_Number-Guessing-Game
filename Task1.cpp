#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <iomanip>
using namespace std;

void printUnderline(int length)
{
    for (int i = 0; i < length; ++i)
    {
        cout << "-";
    }
    cout << endl;
}

void printIndent(int count)
{
    for (int i = 0; i < count; ++i)
    {
        cout << " ";
    }
}

void printCentered(string text, int totalWidth)
{
    int leftPadding = (totalWidth - text.length()) / 2;
    cout << setw(leftPadding + text.length()) << text << endl;
}

int main()
{
    int num, guess, tries = 0;
    char playAgain;

    cout << endl;
    printCentered("Welcome to the Number Guessing Game!", 40);
    printUnderline(40);

    do
    {
        srand(time(0)); // seed random number generator
        num = rand() % 100 + 1; // random number between 1 and 100
        tries = 0;

        cout << "\nI've selected a number between 1 and 100.\n";
        cout << "Try to guess it!\n\n";

        do
        {
            cout << "    Enter your guess: ";
            cin >> guess;

            // Check for invalid input
            if (cin.fail())
            {
                cout << "Invalid input. Please enter a number.\n";
                cin.clear(); // Clear error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard input buffer
                continue;
            }

            tries++;

            if (guess > num)
                cout << "\n    Too high!\n";
            else if (guess < num)
                cout << "\n    Too low!\n";
            else
                cout << "\n    Correct! You got it in " << tries << " guesses!\n";

        } while (guess != num);

        cout << "\n    Do you want to play again? (Y/N): ";
        cin >> playAgain;

    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "\nThanks for playing!\n";

    return 0;
}
