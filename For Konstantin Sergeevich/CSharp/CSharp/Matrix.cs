using System;
using System.Collections.Generic;
using System.Text;

namespace CSharp
{
    class Matrix:
        MatrixUtils
    {
        public Matrix(int[][] rawMatrix):
            base(rawMatrix)
        { }

        public Matrix(UInt32 row, UInt32 column):
            base(row, column)
        { }

    }
}
