/*I wrote this because I saw a cool vestaboard on TikTok and decided to recreate here

- I will not be updating this (most likely!).

By AwesomeMc101
Published on 5.28.22
Lunar Guard Technologies
*/

#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <Windows.h>

class Origin {
public:
    std::string send;
    std::vector<size_t> finishedPositions;
    bool setNext = false;
};

char generateRandomChar()
{
    static const char chars[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "!@#$%^&*[]{}<>?/;:+-";
    
    return chars[rand() % (sizeof(chars) - 1)];
}

void print(std::string toPrint)
{
    std::cout << toPrint << "." << std::endl;
    Sleep(50);
    system("cls");
}

void run(Origin og)
{
    std::string cur;
    std::string old = og.send;

    while (cur != old)
    {
        for (int i = 0; i < old.size(); i++)
        {
            //cur
            if (og.finishedPositions.size() == (old.size() - 1))
            {
                //its like if there's one char left just finish the job
                //lot's of times it will take forever with one left
                cur = old;
            }
            else
            {
                if (old[i] != ' ')
                {
                    char random = generateRandomChar();
                    if (old[i] == random)
                    {
                        og.finishedPositions.push_back(i);
                        cur += random;
                    }
                    else
                    {
                        BOOL isDone = 0;
                        for (size_t j : og.finishedPositions)
                        {
                            if (j == i)
                            {
                                cur += old[i];
                                isDone = 1;
                            }
                            if (isDone)
                            {
                                break;
                            }
                        }
                        if (!isDone)
                        {
                            cur += random;
                        }
                    }


                }
                else
                {
                    cur += ' ';
                }
            }
        }
        print(cur);
        if (cur != old)
        {
            cur.clear();
        }
        else
        {
            std::cout << cur << std::endl << "Done!" << std::endl;
        }
    }
   
}

int main()
{
    srand(time(NULL));
    Origin og;
    //og.send = "Hello World!";
    std::getline(std::cin, og.send);
    run(og); 
}
