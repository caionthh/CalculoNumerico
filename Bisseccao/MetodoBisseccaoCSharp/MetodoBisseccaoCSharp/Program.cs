using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using CalcNumericoUtilCSharp;

namespace MetodoBisseccaoCSharp
{
    class Program
    {
        static void Main(string[] args)
        {

            Calculate c = new Calculate();
            c.Bissec(10);
/*
            for (int i = 0; i < eq.Count; i++)
            {

                if (eq[i] >= 0)
                    Console.Write(" +" + eq[i] + "x^" + exp[i]);
                else
                    Console.Write(" " + eq[i] + "x^" + exp[i]);
            }

    */
            Console.ReadKey();
        }
    }
}
