using System;
using System.Collections.Generic;
using System.Runtime.CompilerServices;
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
            int maxCircle = (int)Math.Min(Row, Column) / 2 % 2 == 0 ? (int)Math.Min(Row, Column) / 2 : (int)Math.Min(Row, Column) / 2 + 1;
            int i = 0 , j = 0, counter = 1;
        	for (int circle = 0 ; circle < maxCircle ; ++circle)
        	{
            		for (; i < Row - circle ; ++i )
            		{
                		base[i, j] = counter;
                		++counter;
            		}
            		--i;
            		++j;
            		for (; j < (int)Column - circle ; ++j )
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
	
	public void printStrange()
	{
            int max = (int)(Column / 2) ;  
        	for (int i = 0; i < max ; ++i )
        	{
            		for (int j = 0 ; j < Row ; ++j)
            		{
                		Console.Write(base[j, i] + " " + base[(int)Row - j - 1, (int)Column - i - 1] + " ");
            		}
            		Console.Write('\n');
        	}
        	if ((int)Column % 2 == 1 )
        	{
            		for (int i = 0 ; i < (int)Row ; ++i)
                		Console.Write(base[i, max] + " ");
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
