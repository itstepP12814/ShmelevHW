#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

using namespace std;

enum Rate {bad, good, excellent};
enum Genr {Action, Western, Criminal, Documental, Melodrama};
struct VideoShop{

      char moviename[128];
      char director[128];
      int genre;
      int rating;
      int cost;
    };

void printer(int filmNumber,VideoShop* base);
void ratePrintInterpretator(int str);
void genrePrintInterpretator(int str);
VideoShop* createArray(void);
VideoShop* add_New_Movie(VideoShop *DataBase, int** endOfList);
void showAll(VideoShop* DataBase, int ** endOfList);
void chooseGenre(VideoShop* DataBase, int**endOfList);
void namePrinter(int number, VideoShop* base);
void showBest(int **endOfList, VideoShop* GenreBase);
void searcherMoviename(VideoShop* DataBase, int** endOfLine);
void searcherDirector(VideoShop* DataBase, int** endOfLine);
void searcherGenre(VideoShop* DataBase, int** endOfLine);
#endif // HEADER_H
