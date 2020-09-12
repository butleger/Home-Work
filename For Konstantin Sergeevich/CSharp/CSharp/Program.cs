using System;
using System.Threading;
using System.Threading.Tasks;

namespace CSharp
{
    public sealed class Program
    {
        static void Main()
        {
            int row = 3;
            int col = 3;
            int count = 0;
            int[][] a = new int[row][];
            for (int i = 0; i < a.Length; ++i )
            {
                a[i] = new int[col];
                for (int j= 0; j < a[i].Length; j++)
                {
                    a[i][j] = count;
                    count++;
                }
            }

            Matrix m = new Matrix(a);
            m.transposition();
            Console.Write("transposition: \n" + m);
            m.snakeFill();
            Console.Write("snake filling: \n" + m);
            Console.Write("strange output\n  base matrix: \n" + m + "  strange output: \n");
            m.printStrange();
        } 
    }
}
