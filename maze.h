#ifndef MAZE
#define MAZE

#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <array>

/**
 * @brief Convenção utilizada: unsigned int variavel = (0000); (OESTE,SUL,LESTE,NORTE)
 */
struct Cell
{
    unsigned int backtrack:4;
    unsigned int solution:4;
    unsigned int border:4;
    unsigned int walls:4;
};

struct CellMarker
{
    unsigned int row;
    unsigned int col;
};

#define ROWS 16
#define COLS 12
#define ADJ_SIZE ROWS * COLS
CellMarker startCell = {0, 0};
CellMarker endCell = {ROWS - 1, COLS - 1};
std::array<std::array<Cell, COLS>, ROWS> grid = {};
std::array<std::array<unsigned char, ADJ_SIZE>, ADJ_SIZE> adjacency = {};

unsigned int borderValue(unsigned int a_rows,
                         unsigned int a_cols,
                         unsigned int a_currentRow,
                         unsigned int a_currentCol)
{
    unsigned int result = 0;
    if (a_currentRow == 0)
    {
        result = 0b1000;
    }
    else if (a_currentRow == a_rows - 1)
    {
        result = 0b0010;
    }
    if (a_currentCol == 0)
    {
        result |= 0b0001;
    }
    else if (a_currentCol == a_cols - 1)
    {
        result |= 0b0100;
    }
    return result;
}

void initializeGrid(Cell a_grid[ROWS][COLS], int a_rows, int a_cols)
{
    for (int i = 0; i < a_rows; ++i)
    {
        for (int j = 0; j < a_cols; ++j)
        {
            a_grid[i][j].walls = 0b1111;
            a_grid[i][j].border = borderValue(ROWS, COLS, i, j);
        }
    }
}

void randomizeWalls(Cell a_grid[ROWS][COLS], int a_rows, int a_cols)
{
    srand(time(nullptr));
    for (int i = 0; i < a_rows; ++i)
    {
        for (int j = 0; j < a_cols; ++j)
        {
            a_grid[i][j].walls = rand() % 16 + 1;// 4 BITS, 2^4 = 16
        }
    }
}

void createAdjacencyMatrix(unsigned char** a_grid, int a_rows, int a_cols)
{
    for (int i = 0; i < a_rows; ++i)
    {
        for (int j = 0; j < a_cols; ++j)
        {            
            if (i == j + 1)
            {
                a_grid[i][j] = 'a';
            }
        }
    }
}

void printMatrix(unsigned char a_grid[ADJ_SIZE][ADJ_SIZE], int a_rows, int a_cols)
{
    for (int i = 0; i < a_rows; ++i)
    {
        for (int j = 0; j < a_cols; ++j)
        {
            std::cout << a_grid[i][j];
            if (j < a_cols - 1)
            {
                std::cout << " ";
            }
        }
        if (i < a_rows - 1)
        {
            std::cout << "\n";
        }
    }
}

void createGrid(Cell a_grid[ROWS][COLS], int a_rows, int a_cols)
{
    initializeGrid(a_grid, a_rows, a_cols);
    randomizeWalls(a_grid, a_rows, a_cols);
    printMatrix(adjacency, ROWS * COLS, ROWS * COLS);
}

#endif // MAZE

