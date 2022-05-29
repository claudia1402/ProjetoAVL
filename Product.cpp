#include "Product.h"
#include "Utils.h"



Product::Product(){
    m_cod = -1;
    m_nome = "";
    m_qtde = -1; 
    m_valorUnitario = -1;
}

Product::Product(int cod, const std::string &nome, int qtde, float valorUnitario)
	: m_cod(cod)
	, m_nome(nome)
	, m_qtde(qtde)
	, m_valorUnitario(valorUnitario)
{	
}

int Product::GetCod() const
{
	return m_cod; 
}

void Product::SetCod(int novoCod) 
{
	m_cod = novoCod;
}

std::string Product::GetNome() const 
{
	return m_nome;
}
void Product::SetNome(std::string novoNome) 
{
	m_nome = novoNome;  
}

int Product::GetQtde() const 
{
  	return m_qtde;
}

void Product::SetQtde(int novaQtde)
{
	m_qtde = novaQtde;  
}

float Product::GetValorUnitario() const
{
	return m_valorUnitario;
}

void Product::SetValorUnitario(float novoValor)
{
	m_valorUnitario = novoValor;
}
