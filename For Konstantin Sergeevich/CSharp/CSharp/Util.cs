using System;
using System.Collections.Generic;
using System.Text;

namespace CSharp
{
    class Util
    {
        static public void swap(ref int first,ref int second)
        {
            int temp = first;
            first = second;
            second = temp;
        }
    }
}
