#include <stdio.h>

int board[8][8];

void resetQueen(int i, int j)
{
  int x;

  x = 0;
  while (x < 8)
  {
    --board[x][j];
    --board[i][x];
    int foo;
    foo = j - i + x;
    if (foo >= 0 && foo < 8)
      --board[x][foo];
    foo = j + i - x;
    if (foo >= 0 && foo < 8)
      --board[x][foo];
    ++x;
  }
  board[i][j] = 0;
}

void setQueen(int i, int j)
{
  int x;

  x = 0;
  while (x < 8)
  {
    ++board[x][j];
    ++board[i][x];
    int foo;
    foo = j - i + x;
    if (foo >= 0 && foo < 8)
      ++board[x][foo];
    foo = j + i - x;
    if (foo >= 0 && foo < 8)
      ++board[x][foo];
    ++x;
  }
  board[i][j] = -1;
}

int tryQueen(int i)
{
  int j;
  j = 0;
  int result = 0;
  while (j < 3)
  {
    if(board[i][j] == '.')
    {
      setQueen(i, j);
      if (i == 7)
        result = 1;
      else
        {
          if (!(result = tryQueen(i + 1)))
            resetQueen(i, j);
        }
    }
    if (result)
      break;
    ++j;
  }
  return (result);
}

int main()
{
  int i;
  int j;

  i = 0;
  j = 0;
  while (i < 3)
  {
    while (j < 3)
    {
      board[i][j] = '.';
      ++j;
    }
    ++i;
  }
  tryQueen(0);
}
