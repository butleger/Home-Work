using System;
using System.Collections.Generic;
using System.Text;

namespace CSharp
{
    class MatrixUtils:
        BaseMatrix
    {
        public MatrixUtils(UInt32 row, UInt32 column):
            base(row, column)
        { }

        public MatrixUtils(int[][] rawMatrix):
            base(rawMatrix)
        { }

        public void snakeFill()
	{
        
        	int maxCircle = Math.Min(mtrx.Length, mtrx[0].Length) / 2;
        	for (int circle = 0 ; circle < maxCircle ; ++circle)
        	{
            		for (; i < rows - circle ; ++i )
            		{
                		base[i, j] = counter;
                		++counter;
            		}
            		--i;
            		++j;
            		for (; j < cols - circle ; ++j )
            		{	
                		base[i, j] = counter;
                		++counter;
            		}
            		--j;
            		--i;
            		for (; i >= circle ; --i)
            		{
                		base[i, j] = counter;
                		++counter;
            		}
            		++i;
            		--j;
            		for (; j > circle ; --j )
            		{
                		base[i, j] = counter;
                		++counter;
            		}
            		++i;
            		++j;
        	}
	}
	
	static void printStrange()
	{
        	int max = rows / 2;  
        	for (int i = 0; i < max ; ++i )
        	{
            		for (int j = 0 ; j < rows ; ++j)
            		{
                		Console.Write(base[j, i] + " " + base[rows - j - 1, cols - i - 1] + " ");
            		}
            		Console.Write('\n');
        	}
        	if (rows % 2 == 1 )
        	{
            		for (int i = 0 ; i < cols ; ++i)
                		Console.Write(base[rows/2 + 1, i]);
        	}
            
    	}

        public void transposition()
        {
            for (int i = 0; i < Row; ++i)
                for (int j = i; j < Column; ++j)
                {
                    int temp = base[i, j];
                    base[i, j] = base[j, i];
                    base[j, i] = temp;
                }                    
        }
    }
}
