using System;

//Membros estáticos são acessíveis por uma classe,ex: classe console
//Membros Instânciados são acessíveis por um objeto

namespace ConsoleApp1
{
    public class ClasseExemplo
    {
        public string campoString;
        public int campoInteiro;
        public float campoFlutuante;

        public ClasseExemplo(string varString, int varInteiro, float varFlutuante)
        {
            campoString = varString;
            campoInteiro = varInteiro;
            campoFlutuante = varFlutuante;
        }

        public string StringAlterada()
        {
            char[] newString = campoString.ToCharArray();
            for (int i = 0; i < campoString.Length; i++)
            {
                newString[i] = (char)(campoString[i] + (i + 1));
            }
            return new string(newString);
        }

        public double PotenciaFlutuante()
        {
            return Math.Pow(campoInteiro, campoFlutuante);
        }
        public static void RetornarConteudo(ClasseExemplo objeto)
        {
            Console.WriteLine("{0} | {1} | {2}", objeto.campoString, objeto.campoInteiro, objeto.campoFlutuante);
        }

        public static void Main(string[] args)
        {
            ClasseExemplo objetoExemplo = new ClasseExemplo("Matheus", 26, 1.15f);

            Console.WriteLine(objetoExemplo.StringAlterada());
            Console.WriteLine(objetoExemplo.PotenciaFlutuante());
            RetornarConteudo(objetoExemplo);
        }
    }
}