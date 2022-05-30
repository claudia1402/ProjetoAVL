#include "Alimento.h"
#include "Utils.h"

Alimento::Alimento(){
    m_nome = "";
	std::list<float> m_nutrientes;
}

Alimento::Alimento(std::string dados[])
{
	m_nome = dados[0];
	for (int i = 1; i < 11; i++)
		m_nutrientes.push_back(std::stof(dados[i]));
}

std::string Alimento::GetNome() const 
{
	return m_nome;
}

void Alimento::SetNome(std::string novoNome) 
{
	m_nome = novoNome;
}

std::list<float> Alimento::GetNutrientes()
{
	return m_nutrientes;
}
