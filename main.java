// Engenharia de Software Moderna - Princ�pios de Projeto (Cap. 5)
// Prof. Marco Tulio Valente
// 
// Exemplo de conceitos b�sicos de OO
//
// O exemplo est� em Java, mas o foco n�o est� na sintaxe dessa 
// linguagem, mas em conceitos b�sicos de orienta��o a objetos

import java.time.Year;

// Primeiro exemplo de classe: Pessoa
// Usado para explicar os conceitos de atributos, 
// m�todos, construtores e visibilidade (p�blico e privado)

class Pessoa {
  // atributos (privados)  
  private String nome;
  private int anoNasc;

  // construtor 
  public Pessoa(String nome, int anoNasc) {
    this.nome = nome;
    this.anoNasc = anoNasc;
  }

  // m�todo privado: somente pode ser chamado "dentro" da classe
  private int getAnoAtual() {
    return Year.now().getValue();
  }

  // m�todo p�blico
  public int calculaIdade() {
    return getAnoAtual() - anoNasc;
  }

}

// Classe simples, que ser� usada depois para explicar composi��o
class Departamento {
  private String nome;

  public Departamento (String nome) {
    this.nome = nome;
  }
}

// Classe usada para explicar heran�a e composi��o
// Heran�a: Professor "�" uma Pessoa
// Composi��o: Professor "tem" um Departamento    

class Professor extends Pessoa { // heran�a (extends)
  private String titulacao;   
  private Departamento depto;    // composi��o (atributo)

  public Professor(String nome, int anoNasc, String titulacao, Departamento depto) {
    super(nome, anoNasc);  // chama construtora da superclasse (Pessoa)
    this.titulacao = titulacao;  // inicializa atributos que existem apenas
    this.depto = depto;          // em Professor
  }

  public String getTitulacao() {
    return this.titulacao;
  }
}


// Classe principal do exemplo
// Cria alguns objetos e chama seus m�todos
class Main {
  
  public static void main(String[] args) {
    // cria objeto da classe Pessoa e chama construtor
    Pessoa p1 = new Pessoa("Jo�o", 2012);

    // cria outro objeto da classe Pessoa
    Pessoa p2 = new Pessoa("Maria", 2002);
    
    // chama metodo p�blico calculaIdade() de p1 e p2
    System.out.println("\nExemplo de classes e objetos:");
    System.out.println("Jo�o tem " + p1.calculaIdade() + " anos");
    System.out.println("Maria tem " + p2.calculaIdade() + " anos");

    Departamento dept = new Departamento ("Computa��o");
    Professor prof1 = new Professor ("Jos�", 1982, "doutor", dept);

    System.out.println ("\nExemplo de heran�a e composi��o:");

    // chama m�todo herdado da superclassse (Pessoa)
    System.out.println ("Jos� tem " + prof1.calculaIdade() + " anos");

    // chama m�todo pr�prio da subclasse (Professor)
    System.out.println ("Jos� � um " + prof1.getTitulacao());
  }
}
