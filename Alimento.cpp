#include "Alimento.h"
#include "Utils.h"

Alimento::Alimento(){
    m_cod = -1;
    m_nome = "";
    m_qtde = -1; 
    m_valorUnitario = -1;
}

Alimento::Alimento(int cod, const std::string &nome, int qtde, float valorUnitario)
	: m_cod(cod)
	, m_nome(nome)
	, m_qtde(qtde)
	, m_valorUnitario(valorUnitario)
{	
}

int Alimento::GetCod() const
{
	return m_cod; 
}

void Alimento::SetCod(int novoCod) 
{
	m_cod = novoCod;
}

std::string Alimento::GetNome() const 
{
	return m_nome;
}
void Alimento::SetNome(std::string novoNome) 
{
	m_nome = novoNome;  
}

int Alimento::GetQtde() const 
{
  	return m_qtde;
}

void Alimento::SetQtde(int novaQtde)
{
	m_qtde = novaQtde;  
}

float Alimento::GetValorUnitario() const
{
	return m_valorUnitario;
}

void Alimento::SetValorUnitario(float novoValor)
{
	m_valorUnitario = novoValor;
}
