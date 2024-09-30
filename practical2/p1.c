/* Create records that implement the test, which has 20 questions, 5 answers to each question and a fixed correct answer.
 * Write an algorithm for the implementation of this test, 
 * if the order of questions and answers changes with the implementation of each algorithm
 * and the correct answer is announced after entering the user's answer.
 * For solution use set properties.*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//program constant variables
#define MAX_TEXT_LENGHT 256
#define QUESTION_COUNT 20
#define ANSWER_COUNT 4

// the data structure of a question
struct question {
    char text[MAX_TEXT_LENGHT];
    char answers[4][MAX_TEXT_LENGHT];
    int correctAnswer;
};

// this function returns a list of questions
// here I set properties of the question object/struct
struct question* getQuestions() {
    static struct question questions[] = {
        {"What is the capital of France?", {"Paris", "Berlin", "Madrid", "Rome"}, 0},
        {"Which planet is known as the Red Planet?", {"Earth", "Mars", "Venus", "Jupiter"}, 1},
        {"Who wrote 'Romeo and Juliet'?", {"Charles Dickens", "Mark Twain", "William Shakespeare", "Homer"}, 2},
        {"What is the largest ocean on Earth?", {"Atlantic Ocean", "Indian Ocean", "Arctic Ocean", "Pacific Ocean"}, 3},
        {"Which element has the chemical symbol 'O'?", {"Oxygen", "Gold", "Osmium", "Oganesson"}, 0},
        {"In which year did World War II end?", {"1939", "1941", "1945", "1948"}, 2},
        {"Which country is known as the Land of the Rising Sun?", {"China", "Japan", "South Korea", "Thailand"}, 1},
        {"What is the hardest natural substance on Earth?", {"Gold", "Iron", "Diamond", "Platinum"}, 2},
        {"Who developed the theory of relativity?", {"Isaac Newton", "Albert Einstein", "Galileo Galilei", "Nikola Tesla"}, 1},
        {"Which language is the most spoken worldwide?", {"Spanish", "English", "Hindi", "Mandarin Chinese"}, 3},
        {"How many continents are there?", {"5", "6", "7", "8"}, 2},
        {"Which is the smallest planet in the Solar System?", {"Mercury", "Venus", "Mars", "Earth"}, 0},
        {"What is the square root of 64?", {"6", "7", "8", "9"}, 2},
        {"Who painted the Mona Lisa?", {"Vincent Van Gogh", "Claude Monet", "Leonardo da Vinci", "Pablo Picasso"}, 2},
        {"What is the longest river in the world?", {"Amazon", "Yangtze", "Nile", "Mississippi"}, 2},
        {"What is the chemical formula for water?", {"H2O", "CO2", "NaCl", "O2"}, 0},
        {"Which planet is known for its rings?", {"Mercury", "Mars", "Saturn", "Venus"}, 2},
        {"What is the main ingredient in guacamole?", {"Tomato", "Cucumber", "Avocado", "Onion"}, 2},
        {"Who discovered penicillin?", {"Marie Curie", "Alexander Fleming", "Louis Pasteur", "Joseph Lister"}, 1},
        {"Which country has the largest population?", {"USA", "India", "China", "Russia"}, 2}
    };
    return questions;
}

// Fisher–Yates shuffle Algorithm O(n) time
// This function does not have a return value
// becuse it directly modifies the array memory
void shuffle(int* array, int size) {
    for(int i = size-1; i > 0; i--) {
        
        // Generate a random index from 0 to i
        int j = rand() % (i + 1);
        
        // swamp i and j index elements
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}
//=======================================
// PROGRAM STARTS HERE, THE MAIN FUNCTION
//======================================
int main() {

    //===================
    //Initilazing variables
    //===================

    // a list of questinos
    struct question* questions = getQuestions();
    // answer letters
    char aLett[] = {'A', 'B', 'C', 'D'};

    // create order lists for questions and answers
    int questionOrder[QUESTION_COUNT];
    for(int i = 0; i < QUESTION_COUNT; i++) {
        questionOrder[i] = i;
    }
    int answerOrder[ANSWER_COUNT];
    for(int i = 0; i < ANSWER_COUNT; i++) {
        answerOrder[i] = i;
    }
    // Seed the random number generator
    srand(time(0));
    // shuffle the order of the questions
    shuffle(questionOrder, QUESTION_COUNT);

    //stores the current question
    struct question* Q;
    //stores user inputed answer
    char userAnswer;
    // How many answers user got right
    int score = 0;

    //================
    //Quizing the user
    //================

    // loop trouhg the questions and quiz the user        
    for (int i = 0; i < QUESTION_COUNT; i++) {
        // current quesion
        Q = &questions[questionOrder[i]];

        //print question text
        printf("%s\n", Q->text); 
        
        //print answers
        shuffle(answerOrder, ANSWER_COUNT);
        for(int j = 0; j < ANSWER_COUNT; j++) {
            printf("    %c) %s\n", aLett[j], Q->answers[answerOrder[j]]);
        }

        // Get user answer and check it
        printf("Answer: ");
        scanf("%c", &userAnswer);

        // cool ascii code arithmetic
        // A - 65 = 0; B - 65 = 1; C - 65 = 2; D - 65 = 3
        if(answerOrder[toupper(userAnswer) - 65] == Q->correctAnswer) {
            printf("Correct!\n");
            score++;
        }
        else {
            printf("Incorrect! The correct answer was %s!\n", Q->answers[Q->correctAnswer]);
        }
        

        // Clear the input buffer
        scanf("%*[^\n]");
        scanf("%*c");
        printf("\n\n");
    }

    printf("You got %d/%d questions right!\n", score, QUESTION_COUNT);

    return 0; // return success code 0
}
