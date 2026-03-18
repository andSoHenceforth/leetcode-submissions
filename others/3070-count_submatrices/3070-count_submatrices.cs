using System;

public class Program
{
	public static void Main()
	{
		int[][][] grids = {
            [[1, 2], [3, 4]],
            [[7, 6, 3], [6, 6, 1]],
            [[7,2,9],[1,5,0],[2,6,6]]
        };
        int[] ks = [10, 18, 20];
        int[] exp = [4, 4, 6];
		for (int i = 0; i < grids.Length; ++i) {
            int[][] currGrid = grids[i];
            int currK = ks[i], currE = exp[i];
            int res = CountSubmatrices(currGrid, currK);
            string currGridTxt = string.Join(", ", currGrid.Select(r =>"[" + string.Join(", ",r)+"]"));
            string testStatus = (currE == res) ? "O" : "X";
            Console.WriteLine($"{testStatus} Test | Input: {currGridTxt}; output: {res}; expected: {currE}");
        }

	}
	
	public static int CountSubmatrices(int[][] grid, int k) {
        // Summation of an entire submatrix is:
        // $\text{Sum}(i, j) = \sum_{r=0}^{i} \sum_{c=0}^{j} \text{grid}[r][c]$
        int n = grid.Length; 
        int m = grid[0].Length;
        int[] cols = new int[m];
        int res = 0;

        // Proceed by row-major order
        for (int i = 0; i < n; ++i) {
            int rows = 0;  // Summation of the current row
            for (int j = 0; j < m; ++j) {
                cols[j] += grid[i][j];
                rows += cols[j];
                if (rows <= k) {
                    res++;
                }
            }
        }
        return res;
    }
}