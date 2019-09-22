using System;

namespace offlineTest
{
    class Program
   {
        static void Main(string[] args)
        {
            Solver solver = new Solver();
            var result = solver.GetStart( 2 );
            Console.WriteLine(result);
        }
    }
}
