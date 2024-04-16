#include <stdbool.h>
#include <stdio.h>

bool validcheck(int num, int rowpos, int colpos,int grid[][9]){
  for (int i=0; i<9; i++){ // check if row is valid    
    if(grid[i][colpos] == num){
      return false;
    }
  }

  for(int x=0; x<9; x++){
    if(grid[rowpos][x] == num){ // check if col is valid
      return false;
    }
  }

    int startRow = rowpos - rowpos % 3; // Początkowy wiersz kwadratu 3x3
    int startCol = colpos - colpos % 3; // Początkowa kolumna kwadratu 3x3
    for (int x = startRow; x < startRow + 3; x++) { // Sprawdź kwadrat 3x3
        for (int y = startCol; y < startCol + 3; y++) {
            if (grid[x][y] == num) {
                return false;
            }
        }
  }
  return true;
}

void rbprint(int grid[][9]){
  // print rubics cube
  printf("-------------------\n");
  for(int x=0; x<9; x++){ // rowdraw
    printf("|");
    for(int y=0; y<9; y++){
      printf(" %d |", grid[x][y]);
    }
    printf("\n");
  } 
  printf("-------------------\n");
  }

bool solve(int grid[][9],int r,int c){
  if(r==9){
    return true;
  }
  else if (c == 9) {
    return solve(grid, r+1, 0);
  }
  else if (grid[r][c] != 0) {
    return solve(grid, r, c+1); 
  }
  else{
    for(int k=1; k<10; k++){
      if(validcheck(k, r, c, grid) == true){
        grid[r][c] = k;

        if(solve(grid, r, c+1)){
          return true;

        }

        grid[r][c] = 0;
      }
    }
    return false;
  }

}



int main(void) {
  int grid[9][9] = { // [wiersz][kolumna]
      {0, 0, 4, 0, 5, 0, 0, 0, 0},
      {9, 0, 0, 7, 3, 4, 6, 0, 0},
      {0, 0, 3, 0, 2, 1, 0, 4, 9},
      {0, 3, 5, 0, 9, 0, 4, 8, 0},
      {0, 9, 0, 0, 0, 0, 0, 3, 0},
      {0, 7, 6, 0, 1, 0, 9, 2, 0},
      {3, 1, 0, 9, 7, 0, 2, 0, 0},
      {0, 0, 9, 1, 8, 2, 0, 0, 3},
      {0, 0, 0, 0, 6, 0, 1, 0, 0} 
  };

  if (solve(grid, 0, 0)) {
        printf("rozwiązanie sudoku:\n");
        rbprint(grid);
    } else {
        printf("brak rozwiązania dla podanego sudoku.\n");
    }
  return 0;
}
