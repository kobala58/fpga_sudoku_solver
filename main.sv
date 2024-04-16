
module rubics ();

reg [7:0] grid [0:8][0:8]; // 8bit 9x9 sudoku grid

initial begin

   for (int i=0; i<=3; i++) begin
      a[i] = i[7:0];
   end

   c = a[0];
   d = a[1][2]; 


   // using 2D
   for (int i=0; i<=3; i++)
      for (int j=0; j<=3; j++)
          b[i][j] = i*j;  // watch this if you're building hardware

end
