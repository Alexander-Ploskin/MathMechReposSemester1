using System;

namespace Task1
{
    class Program
    {
        public static int CalculatingOfFactorial(int inputNumber)
        {
            if (inputNumber < 2)
            {
                return 1;
            }

            return inputNumber * CalculatingOfFactorial(inputNumber - 1);
        }
        static void Main(string[] args)
        {
            Console.WriteLine("Enter the number:");
            int number = int.Parse(Console.ReadLine());
            Console.WriteLine($"Factorial of {number} is {CalculatingOfFactorial(number)}");
        }
    }
}
