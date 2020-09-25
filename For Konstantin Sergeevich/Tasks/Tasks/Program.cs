using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Tasks
{
    class Program
    {
        public static Semaphore sem = new Semaphore(4, 4);
        static void Main(string[] args)
        {
            int qttyWorkers = 10;
            Task[] workers = new Task[qttyWorkers];
            for (int i = 0; i < workers.Length; ++i)
            {
                workers[i] = Task.Run(Work);
            }

            Task.WaitAll(workers);
        }

        static public void Work()
        {
            sem.WaitOne();
            Stopwatch timer = new Stopwatch();
            timer.Start();
            Console.WriteLine($"{Thread.CurrentThread.ManagedThreadId} is in the Work!");
            Thread.Sleep(1000);
            timer.Stop();
            Console.WriteLine($"{Thread.CurrentThread.ManagedThreadId} end its Work and do shit about {timer.ElapsedMilliseconds * 1.0/1000} sec!");
            sem.Release();
        }
    }
}
