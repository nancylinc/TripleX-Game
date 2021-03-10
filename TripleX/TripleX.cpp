#include <iostream>
#include <ctime>
//# >> processor directory <> >> header file
// instructing the compiler to copy the contents if the iostream header file into our code
// before rest of the code is compiled

void PrintIntroduction(int Difficulty)
{
    //print welcome message to terminal
    //std << namespace << prevent same name; :: Scope Operator; Cout << print out to terminal
    // \n switch line same as std::endl
     std::cout << "\n\nYou are a scret agent hacking into a level "<< Difficulty;  
     std::cout << "security system\nTo secure weapon system on the ship.. \nYou need to enter the correct codes to continue...\n\n";
 
}

bool PlayGame(int Difficulty)
{
    
    PrintIntroduction(Difficulty);
   
    // Declare 3 number code
    const int CodeA = rand() % Difficulty+1; 
    const int CodeB = rand() % Difficulty+1;
    const int CodeC = rand() % Difficulty+1;

    const int CodeSum = CodeA + CodeB + CodeC;// const means you can't change the variable
    const int CodeProduct = CodeA * CodeB * CodeC;


    std::cout << "\n+ there are 3 numbers in the code\n";
    std::cout  << "+ the codes add up to "<< CodeSum  ;
    std::cout << "\n+ the codes multiply to "<< CodeProduct << std::endl;

    int GuessA, GuessB, GuessC;

    // Get player input
    std::cin >> GuessA >> GuessB >> GuessC;

    // print player guess  
    std::cout << "\nYou entered: " << GuessA << GuessB << GuessC;


    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // check if its right passward
    if(GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nCorrect passward";
        return true;
    }
    else
    {
        std::cout << "\nWrong passward";
        return false;
    }

}


int main()
{  
    srand(time(NULL));// create new random sequence based on time of the day

    int LevelDifficulty = 1;
    const int MaxLevelDifficulty = 10;

    while(LevelDifficulty<= MaxLevelDifficulty)// Loop Game till the level is completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();//clear any errors
        std::cin.ignore();//Discards the buffer

        if(bLevelComplete)
        {
            ++LevelDifficulty;
        }
    }
    std::cout <<"\n Weapon system is down \n  Attacking main ship \n Well done agent";
    return 0;
}