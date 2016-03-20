using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CalcNumericoUtilCSharp
{
    public static class Function
    {

        //Ler uma equação em um vetor
        public static List<double> readEquation (out List<double> expo, string endCondition = "")
        {
            //Lista de valores
            List<double> eq = new List<double>();
            List<double> exp = new List<double>();

            //Lista final
            List<double> eqLido = new List<double>();
            List<double> eqSum = new List<double>();
            List<double> expSum = new List<double>();

            //Info
            Console.WriteLine("Insira os valores da equação, na seguinte ordem: Ax^b");
            Console.WriteLine("Primeiramente o valor A (pressione enter), depois o valor do expoente.");

            //Ler valores
            Console.WriteLine("Insira os valores: ");
            string read = "";
            string expRead = "";
            while ((read = Console.ReadLine()) != endCondition)
            {
                //Ler
                expRead = Console.ReadLine();

                //Adicionar na lista
                try {
                    eq.Add(Convert.ToDouble(read));
                    exp.Add(Convert.ToInt32(expRead));
                }
                catch (Exception e)
                {
                    break;
                }

            }

            //Pular linha
            Console.WriteLine();

            //Somar expoentes iguais
            foreach(double e in exp)
            {
                //Não contem o expoente atual
                if (!eqLido.Contains(e))
                {
                    //Soma
                    double aSum = 0;

                    //Rodar lista de expoentes
                    for (int i = 0; i < exp.Count; i++)
                    {
                        if (e == exp[i])
                        {
                            aSum += eq[i];
                        }
                    }

                    //Montar
                    eqSum.Add(aSum);
                    expSum.Add(e);

                    //Adicionar aos lidos
                    eqLido.Add(e);
                }
            }

            //return
            expo = expSum;
            return eqSum;
        }

        //Calcular
        public static double calculateEquation(double x, List<double>eq, List<double>exp)
        {
            double result = 0;

            //Ler
            for (int i = 0; i < eq.Count; i++)
            {
                result += (eq[i]) * (Math.Pow(x, exp[i]));
            }

            return result;
        }


    }
}
