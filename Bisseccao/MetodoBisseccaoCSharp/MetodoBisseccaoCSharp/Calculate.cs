using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using CalcNumericoUtilCSharp;

namespace MetodoBisseccaoCSharp
{
    public class Calculate
    {

        //Bisseccao
        public void Bissec(int interacoes)
        {
            //Escreva a função
            List<double> exp;
            List<double> eq = Function.readEquation(out exp);

            //Valores
            double min, max;
            Console.WriteLine("Digite o minimo e maximo da bissecção:");
            min = Convert.ToDouble(Console.ReadLine());
            max = Convert.ToDouble(Console.ReadLine());
            double val = Function.calculateEquation(min, eq, exp) * Function.calculateEquation(max, eq, exp);
            Console.WriteLine(val);


        }

    }
}
