using sistemaBanco.Modelos;
using System;

namespace sistemaBanco
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Escreva o nome do titular da conta: ");
            string novoTitularNome = Console.ReadLine();

            Console.WriteLine("Escreva a quantia que você quer depositar: ");
            double quantiaADepositar = double.Parse(Console.ReadLine());


            var conta = new Conta();

            conta.NumeroAgencia = 123;
            conta.NumeroConta = 123456789;
            conta.Depositar(quantiaADepositar);

            conta.Titular = new Titular()
            {
                Nome = novoTitularNome,
                Identidade = "111.111.111.-11",
                Endereco = "Rua 15 de Novembro"
            };

            Console.WriteLine("Olá, " + conta.Titular.Nome + "!" + " Sua conta foi criada.");
            Console.WriteLine("Seu saldo é de: " + conta.VerSaldo());

        }
    }
}
