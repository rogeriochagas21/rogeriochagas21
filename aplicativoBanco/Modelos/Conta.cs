using System;
using System.Collections.Generic;
using System.Text;

namespace sistemaBanco.Modelos
{
    internal class Conta
    {
        public int NumeroAgencia { get; set;  }
        public int NumeroConta { get; set;  }
        private double Saldo { get; set;  }
        public Titular Titular { get; set; }

        public void Depositar(double valor)
        {
            double taxa = 0.01;
            Saldo = valor - valor * taxa;
        }

        public double VerSaldo()
        { 
            return Saldo;
        }
               
    }
}
