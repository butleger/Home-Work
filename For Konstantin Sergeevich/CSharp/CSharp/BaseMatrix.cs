using System;
using System.Collections.Generic;
using System.Text;

namespace CSharp
{
    class BaseMatrix
    {
        private int[][] matrix;
        protected UInt32 Row { get; set; }
        protected UInt32 Column { get; set; }
        
        public BaseMatrix(UInt32 row, UInt32 column)
        {
            this.Column = column;
            this.Row = row;
            this.matrix = new int[row][];
            for (int i = 0; i < row; ++i)
                matrix[i] = new int[column];
        }
        
        public BaseMatrix(int[][] rawMatrix)
        {
            this.matrix = rawMatrix;
            this.Row = (UInt32)rawMatrix.Length;
            this.Column = (UInt32)rawMatrix[0].Length;
        }

        public int this[int i, int j]
        {
            get
            {
                return matrix[i][j];
            }
            set
            {
                matrix[i][j] = value;
            }
        }

        public static implicit operator String(BaseMatrix mtrx)
        {
            String result = "";
            for (int i = 0; i < mtrx.Row; ++i)
            {
                for (int j = 0; j < mtrx.Column; ++j)
                    result += mtrx[i, j] + " ";
                result += '\n';
            }
            return result;
        }

    }
}
