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

        public void snakeFilling()
        {

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
