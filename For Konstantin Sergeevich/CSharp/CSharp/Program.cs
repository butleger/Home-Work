using System;
using System.Collections.Generic;
using System.Runtime.CompilerServices;
using System.Threading;
using System.Threading.Tasks;

namespace CSharp
{
    internal class Test:
        IComparable<Test>
    {
        private int value;

        public Test(int value)
        {
            this.value = value;
        }
        int IComparable<Test>.CompareTo(Test t1) 
        {
            return this.value - t1.value;
        }

        public static implicit operator String(Test test)
        {
            return "Test = " + test.value;
        }
    }

    public sealed class Program
    {
        static void TestTest()
        {
            List<Test> l = new List<Test>() { new Test(1), new Test(2), new Test(3) };
            l.Sort();

            foreach (var el in l)
            {
                Console.Write(el + " ");
            }

            Console.WriteLine('\n');
        }
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
            Console.WriteLine("\n=====================================================================");
            TestTest();
        } 
    }
}
