#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
using namespace std;

void initializeMatrix(char **&matrix, int row, int col);
void readDataMatrix(ifstream &ifs, char **&matrix, int row, int col);
void printMatrix(char **&matrix, int row, int col);
void freeMatrix(char **&matrix, int row, int col);

    int calculateHydroBondings(char** dna,int numOfNucleotides)
{
    for ( int i = 0;i < numOfNucleotides;i++)
    {
        if ( dna[0][i] == 'A' ) dna[1][i] = 'T';
        else if ( dna[0][i] == 'T' ) dna[1][i] = 'A';
        else if ( dna[0][i] == 'G' ) dna[1][i] = 'C';
        else if ( dna[0][i] == 'C' ) dna[1][i] = 'G';

    }
    for ( int i = 0;i < numOfNucleotides;i++)
    {
        if ( dna[1][i] == 'A' ) dna[0][i] = 'T';
        else if ( dna[1][i] == 'T' ) dna[0][i] = 'A';
        else if ( dna[1][i] == 'G' ) dna[0][i] = 'C';
        else if ( dna[1][i] == 'C' ) dna[0][i] = 'G';
    }
    
    
    int countA = 0 ,countC = 0;
    
        for (int j = 0 ; j < numOfNucleotides ; j++)
        {
            if ( dna[0][j] == 'A' || dna[0][j] == 'T'  )
            countA++;
            else countC++;
        }
        //cout << countA <<" "<<countC<<'\n';
        return countA*2 + countC*3;
    
}
    

int main(int argc, char **argv)
{
    ifstream ifs;
    ifs.open(argv[1], ifstream::in);

    int numOfNucleotides;
    ifs >> numOfNucleotides;

    char** dna;
    initializeMatrix(dna, 2, numOfNucleotides);
    readDataMatrix(ifs, dna, 2, numOfNucleotides);

    printf("Hydro bondings: %d", calculateHydroBondings(dna, numOfNucleotides));

    freeMatrix(dna, 2, numOfNucleotides);
    ifs.close();
    return 0;
}

void initializeMatrix(char **&matrix, int row, int col)
{
    matrix = new char *[row];
    for (int i = 0; i < row; i++)
    {
        matrix[i] = new char[col];
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

void readDataMatrix(ifstream &ifs, char **&matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            ifs >> matrix[i][j];
        }
    }
}

void printMatrix(char **&matrix, int row, int col) {
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}

void freeMatrix(char **&matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
}